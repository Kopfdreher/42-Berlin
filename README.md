# 42 Berlin - The Common Core ✅

![42 Berlin](https://img.shields.io/badge/School-42_Berlin-black?style=for-the-badge&logo=42)
![Language](https://img.shields.io/badge/Language-C_%2F_C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Common_Core_Completed-success?style=for-the-badge)
![Graduated](https://img.shields.io/badge/42-Graduated-gold?style=for-the-badge)

## 👋 About
This repository documents my entire journey through the **Common Core** curriculum at **42 Berlin** — **now complete**.

42 is a global coding school with no teachers, no classes, and a unique peer-to-peer learning model. The curriculum focuses on building deep computer science fundamentals from scratch — starting with recreating the C standard library and moving into advanced algorithms, graphics, system administration, Object-Oriented Programming, DevOps, and full-stack web development.

**Status: Graduated — all Ranks (0–6) done, including the final `ft_transcendence` project.**

> 💡 **Note:** Some of the bigger group projects live in their own repositories (team setup / submodules / Docker projects). They are linked in the table below and in [Bigger Projects in Separate Repositories](#-bigger-projects-in-separate-repositories).

---

## 🗺️ Curriculum Progress

| Rank | Project | Description | Stack | Status |
|:---:|:---|:---|:---:|:---:|
| **0** | **[Libft](./Rank0/Libft)** | Your very first own C library. Re-coding standard C functions. | C, Makefile | ✅ |
| **1** | **[ft_printf](./Rank1/printf)** | Recreating the `printf` function. Focus on variadic arguments. | C | ✅ |
| **1** | **[get_next_line](./Rank1/get_next_line)** | Reading a line from a file descriptor. Focus on static variables. | C | ✅ |
| **1** | **Born2beroot** | System Administration. Setting up a secure Debian server (LVM, SSH, UFW). | Bash, VM | ✅ |
| **2** | **[push_swap](./Rank2/push_swap)** | Sorting data on a stack with a limited set of instructions using the lowest possible number of moves. | C, Algos | ✅ |
| **2** | **[so_long](./Rank2/so_long)** | A small 2D game. Textures, sprites, and event handling. | C, MiniLibX | ✅ |
| **2** | **[pipex](./Rank2/pipex)** | Simulating the Unix pipe mechanism `\|`. File descriptors and redirection. | C, Unix | ✅ |
| **3** | **[minishell](https://github.com/Kopfdreher/minishell)** | A functional shell. Parsing, executors, built-ins, and signal handling. *→ separate repo, group project with alago-ga.* | C, Bash | ✅ |
| **3** | **[philosophers](./Rank3/philo)** | The Dining Philosophers problem. Threads, mutexes, and concurrency. | C, Threads | ✅ |
| **4** | **[cub3D](https://github.com/Kopfdreher/cub3d)** | A Wolfenstein-3D-style raycaster. Ray-casting with DDA, textured walls, map parsing. *→ separate repo, group project with aabelkis.* | C, MiniLibX, Math | ✅ |
| **4** | **[CPP Modules 00-04](./Rank4/)** | Introduction to OOP: Classes, polymorphism, inheritance, and templates. | C++ | ✅ |
| **4** | **[NetPractice](./Rank4/NetPractice)** | Networking exercises (Subnets, TCP/IP, Routing). | Network | ✅ |
| **5** | **[CPP Modules 05-09](./Rank5/)** | Advanced C++: Exceptions, casting, templates, and containers (STL). | C++ | ✅ |
| **5** | **[Inception](https://github.com/Kopfdreher/inception)** | System Administration with Docker. NGINX (TLS-only) + WordPress/php-fpm + MariaDB from custom Debian images. *→ separate repo.* | Docker, NGINX, WordPress | ✅ |
| **5** | **[webserv](https://github.com/Kopfdreher/webserv)** | Writing an HTTP/1.1 server from scratch in C++98. Sockets, multiplexing, CGI. *→ my fork of the team repo, notes + tutorial in [Rank5/webserv-notes](./Rank5/webserv-notes/).* | C++98, Sockets, HTTP | ✅ |
| **6** | **[ft_transcendence](https://github.com/Kopfdreher/ft_transcendence)** | The final project. Full-stack multiplayer word-game platform **Dicteé** (Word Building + Word Soup, lobbies, WebSockets). *→ my fork of the team project, built with tsternbe, kmooney, smanthey, avarghes.* | TS, NestJS, React, WebSockets, Docker | ✅ |
| **6** | **[Exam prep](./Rank6/examprep)** | Final exam simulations (`mini_serv`, etc.). | C, Unix | ✅ |

---

## 📦 Bigger Projects in Separate Repositories

These were too large / team-based for this monorepo, so they live on their own:

### 🐚 [minishell](https://github.com/Kopfdreher/minishell) — Rank 3
*“As beautiful as a shell.” — with [alago-ga](https://github.com/alago-ga)*
A functional bash-like shell in C: custom lexer/parser, AST, env expansion, quotes, heredoc, infinite pipelines, redirections, built-ins, and signal handling (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`).
* **Stack:** C, readline, `fork` / `execve` / `pipe` / `dup2`

### 🧊 [cub3D](https://github.com/Kopfdreher/cub3d) — Rank 4
*Wolfenstein-style raycaster — with aabelkis.*
DDA ray-casting engine with directional wall textures, floor/ceiling colors, WASD + camera rotation, wall-sliding collision, and strict `.cub` map validation — all pixel-by-pixel with MiniLibX.
* **Stack:** C, MiniLibX, ray-casting math (DDA)

### 🐳 [inception](https://github.com/Kopfdreher/inception) — Rank 5
Docker Compose stack built from scratch: custom Debian images for NGINX (port 443 only, TLS 1.2/1.3), WordPress + php-fpm, and MariaDB. Internal bridge network, named volumes, Docker secrets — no prebuilt images.
* **Stack:** Docker, Docker Compose, NGINX, WordPress, MariaDB
* Run: `make` → https://sgavrilo.42.fr

### 🌐 [webserv](https://github.com/Kopfdreher/webserv) — Rank 5
Custom C++98 HTTP/1.1 server from scratch: non-blocking sockets, multiplexing, request parsing, routing, CGI. My study notes and from-scratch tutorial live in [Rank5/webserv-notes](./Rank5/webserv-notes/).
* **Stack:** C++98, Sockets, HTTP, CGI

### 🎮 [ft_transcendence](https://github.com/Kopfdreher/ft_transcendence) — Rank 6, final project
**Dicteé** — a supervised multiplayer vocabulary platform for kids: parents create groups, import/photograph vocab lists, invite families, and launch real-time **Play Now** sessions. Kids play collaborative **Word Building** (crossword) and **Word Soup** (word search) in a live lobby synced over WebSockets.
* Built with `tsternbe`, `kmooney`, `smanthey`, `avarghes` — see [MODULES.md / DEV.md in the repo](https://github.com/Kopfdreher/ft_transcendence) for eval modules and setup.
* **Stack:** TypeScript, NestJS, React, WebSockets, Docker, ORM

---

## 🏆 Project Highlights

### 🐚 Minishell
*Rank 3 | Group Project — [repo](https://github.com/Kopfdreher/minishell)*
**"As beautiful as a shell."**
A surprisingly complex project requiring us to recreate a functional Unix shell (like bash).
* **Key Challenges:** Writing a custom lexer/parser, managing abstract syntax trees (AST), handling environment variables, implementing pipes/redirections, and managing signals (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`).
* **Skills:** Process creation (`fork`, `execve`), file descriptor manipulation, defensive programming.

### 🧊 Cub3D
*Rank 4 | Group Project — [repo](https://github.com/Kopfdreher/cub3d)*
A first-person maze game à la Wolfenstein 3D.
* **Key Challenges:** DDA ray-casting without fisheye distortion, per-pixel rendering, texture mapping per direction, smooth collision.
* **Skills:** MiniLibX, linear algebra/geometry, map parsing, memory-leak-free C.

### 🍝 Philosophers
*Rank 3 | Concurrency*
**"I eat, therefore I am."**
A solution to the classic Dining Philosophers problem. The goal is to prevent philosophers from dying of starvation while managing shared resources (forks) without getting into data races or deadlocks.
* **Key Challenges:** Synchronization, avoiding race conditions, optimizing CPU usage.
* **Skills:** Threads (`pthread`), Mutexes, Semaphores, Time management.

### 🎨 So_long
*Rank 2 | Graphics*
A small 2D game where a character collects items and escapes a map.
* **Key Challenges:** Handling window management, rendering textures (X11/Cocoa), and key-hook events.
* **Skills:** MiniLibX (42's graphics library), game loops, map parsing.

### 📊 Push_swap
*Rank 2 | Algorithms*
An algorithmic challenge to sort a stack of numbers using two stacks and a specific set of operations, aiming for the lowest complexity.
* **Skills:** Complexity analysis (Big O), stack manipulation, Turk / chunk-based sorting.

### 🧪 Pipex
*Rank 2 | Unix Mechanism*
Recreating the behavior of the shell command: `< infile cmd1 | cmd2 > outfile`.
* **Skills:** Deep understanding of `pipe()`, `dup2()`, and `fork()`.

### 🐳 Inception
*Rank 5 — [repo](https://github.com/Kopfdreher/inception)*
Dockerized LEMP-style stack from zero: TLS-only NGINX entrypoint, WordPress, MariaDB.
* **Skills:** Dockerfiles, Compose networking/volumes/secrets, NGINX + TLS, debugging multi-container systems.

### 🌐 Webserv
*Rank 5 | Group Project — [repo](https://github.com/Kopfdreher/webserv) · [notes + tutorial](./Rank5/webserv-notes/)*
Custom C++98 HTTP/1.1 server: non-blocking sockets, multiplexing (`poll`/`select`), request parsing, routing, CGI.
* **Skills:** Network programming, HTTP spec, file descriptors, C++98 constraints.

### 🎮 Ft_transcendence — Dicteé
*Rank 6 | Final, Group Project — [repo](https://github.com/Kopfdreher/ft_transcendence)*
Real-time multiplayer SPA with chat, lobbies, live games over WebSockets, auth/sessions, and full DevOps (Docker Compose, CI).
* **Skills:** Full-stack TypeScript, NestJS, React, WebSockets, ORM/DB design, teamwork at scale.

---

## 🛠️ Skills & Technologies

* **Languages:** C (Expert), C++ (incl. C++98/STL), TypeScript, Shell Scripting, SQL.
* **Tools:** Git, Vim/Neovim, Valgrind, GDB, Makefiles, Docker & Compose, NGINX.
* **Systems:** Unix/Linux architecture, File Descriptors, Memory Management (malloc/free), Concurrency (Threads/Processes), Sockets & HTTP, Containers & Volumes.
* **Web:** NestJS, React, WebSockets, REST APIs, ORMs.
* **Soft Skills:** Peer-to-peer code reviews, teamwork (Minishell, cub3D, Transcendence), self-learning, technical documentation.

---

## 📬 Contact
[Webseite](https://www.sgavrilov.de) | [LinkedIn](https://www.linkedin.com/in/sergej-gavrilov)

---
*Created by Sergej Gavrilov — 42 Berlin Common Core graduate.*
