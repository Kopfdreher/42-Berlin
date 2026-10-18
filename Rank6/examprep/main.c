#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int sockFd, maxFd, gId = 0;
int clients[2048];
char *msgs[2048];
fd_set readSet, writeSet, current;
char bufRead[1001], bufWrite[100];

int extractMsg(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *strJoin(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void fatal(void) {
	write(2, "Fatal error\n", 12);
	close(sockFd);
	exit(1);
}

void broadcast(int author, char* str) {
	for (int fd = 0; fd <= maxFd; fd++) {
		if (FD_ISSET(fd, &writeSet) && fd != author) send(fd, str, strlen(str), 0);
	}
}

void addClient(void) {
	struct sockaddr_in clientAddr;
	socklen_t len = sizeof(clientAddr);
	int clientFd = accept(sockFd, (struct sockaddr *)&clientAddr, &len);
	if (clientFd < 0) return;
	if (clientFd > maxFd) maxFd = clientFd;

	clients[clientFd] = gId++;
	FD_SET(clientFd, &current);

	msgs[clientFd] = NULL;
	sprintf(bufWrite, "server: client %d just arrived\n", clients[clientFd]);
	broadcast(clientFd, bufWrite);
}

void rmClient(int fd) {
	sprintf(bufWrite, "server: client %d just left\n", clients[fd]);
	broadcast(fd, bufWrite);
	free(msgs[fd]);
	msgs[fd] = NULL;
	FD_CLR(fd, &current);
	close(fd);
}

void sendMsg(int fd) {
	char *msg;
	while (extractMsg(&(msgs[fd]), &msg)) {
		sprintf(bufWrite, "client %d: ", clients[fd]);
		broadcast(fd, bufWrite);
		broadcast(fd, msg);
		free(msg);
	}
}

int main(int argc, char **argv) {
	if (argc != 2) {
    		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	struct sockaddr_in servaddr;
	// socket create and verification 
	sockFd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockFd < 0) fatal();
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 
	// Binding newly created socket to given IP and verification 
	if ((bind(sockFd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) fatal();
	if (listen(sockFd, 128) < 0) fatal();

	FD_ZERO(&current);
	FD_SET(sockFd, &current);
	maxFd = sockFd;

	while (1) {
		readSet = writeSet = current;
		if (select(maxFd + 1, &readSet, &writeSet, NULL, NULL) < 0) fatal();
		for (int fd = 0; fd <= maxFd; fd++) {
			if (!FD_ISSET(fd, &readSet)) continue;
			if (fd == sockFd) {
				addClient();
				break;
			}
			int readBytes = recv(fd, bufRead, 1000, 0);
			if (readBytes <= 0) {
				rmClient(fd);
				break;
			}
			bufRead[readBytes] = '\0';
			msgs[fd] = strJoin(msgs[fd], bufRead);
			sendMsg(fd);
		}
	}
}
