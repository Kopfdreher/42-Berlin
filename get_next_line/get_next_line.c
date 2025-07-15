/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:21:33 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/15 17:21:34 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_ft(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;
	char	*temp;

	buffer = ft_calloc(1, sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while(bytes_read && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		temp = stash;
		stash = ft_strjoin(stash, buffer);
		free(temp);
	}
	return (buffer);
}
/*
char	*get_current_line(int fd)
{
	static char	*stash;

	while (
}
*/
char	*get_next_line(int fd)
{
	static char	*stash;

	stash = read_ft(fd, stash);
	return (stash);
}
