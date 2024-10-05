# holbertonschool-simple_shell
holbertonschool-simple_shell this is a team project on SIMPLE-SHELL

# Content
- MAN_PAGE
- What is the shell ?
- About this project
- Essentiel Fonctionalitie of the simple shell
- File description
- List of allowed functions and system calls fot this project
- Compilation
- valgrind
- Requierment
- Testing code
- Exemple
- BUGS
- Flowchart
- Authors

# MAN_PAGE

# What is the shell ?
A shell is a computer program that provides a user interface for the services of an operating system. It acts as a command interpreter, allowing the user to enter text commands to run programs, manipulate files, navigate directories, and interact with the operating system.

# About this project
About this project simple shell is a simple version of the linux shell made by the holberton school.

# Essential fonctionalities of the simple shell
Entry point of utilisateur
Runs all "executable program" commands (ls, ls -l, /bin/ls, //bin/ls -l)
Executes all buil_in commands (exit, env, getenv)
manage commands with arguments
manage the global PATH variable.
manages the EOF condition (end of file)
handles the Ctrl + c signal -> it does not leave the shell

# Files description
- Shell.h -> header file
- simple_shell.c -> main function main: to enter command system and execute 
- execve.c -> execute extern commands in the shell
- token.c -> strdup.c -> duplicate string and cut it in tokens
- free.c -> free the memory allocate for a 2D array
- read.c -> reads input line from the user and keep it in buffer 
- path.c -> looks for the absolute path of an executable 
- build.c -> used to handle build-in commands
- getenv.c -> get value of environment variable used to keep informations such as configuration parameters etc

# List of allowed functions and system calls for this project
- all functions from string.h
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
_exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- printf (man 3 printf)
- fprintf (man 3 fprintf)
- vfprintf (man 3 vfprintf)
- sprintf (man 3 sprintf)
- putchar (man 3 putchar)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

# Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Testing valgrind
- root@9e07271f045e4bdfa379799071e5c5c9-2377118072:/holbertonschool-simple_shell# - -valgrind ./hsh
- ==165== Memcheck, a memory error detector
- ==165== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
- ==165== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
- ==165== Command: ./hsh
- ==165==
- $ valgrind ./hsh
- ==166== Memcheck, a memory error detector
- ==166== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
- ==166== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
- ==166== Command: ./hsh
- ==166==
- $ ^C==165==
- ==165== Process terminating with default action of signal 2 (SIGINT)
- ==166==
- ==166== Process terminating with default action of signal 2 (SIGINT)
- ==166== at 0x49747E2: read (read.c:26)
- ==165== at 0x494A3EA: wait4 (wait4.c:30)
- ==166== by 0x48ECC35: _IO_file_underflow@@GLIBC_2.2.5 (fileops.c:516)
- ==165== by 0x10961C: exec (in /holbertonschool-simple_shell/hsh)
- ==166== by 0x48E0307: getdelim (iogetdelim.c:73)
- ==165== by 0x109BC1: main (in /holbertonschool-simple_shell/hsh)
- ==166== by 0x109A9C: read_line (in /holbertonschool-simple_shell/hsh)
- ==166== by 0x109B21: main (in /holbertonschool-simple_shell/hsh)
- ==165==
- ==166==
- ==166== HEAP SUMMARY:
- ==166== in use at exit: 1,144 bytes in 2 blocks
- ==166== total heap usage: 2 allocs, 0 frees, 1,144 bytes allocated
- ==166==
- ==165== HEAP SUMMARY:
- ==165== in use at exit: 1,081 bytes in 5 blocks
- ==165== total heap usage: 26 allocs, 21 frees, 2,027 bytes allocated
- ==165==
- ==166== LEAK SUMMARY:
- ==166== definitely lost: 0 bytes in 0 blocks
- ==166== indirectly lost: 0 bytes in 0 blocks
- ==166== possibly lost: 0 bytes in 0 blocks
- ==166== still reachable: 1,144 bytes in 2 blocks
- ==166== suppressed: 0 bytes in 0 blocks
- ==166== Rerun with --leak-check=full to see details of leaked memory
- ==166==
- ==166== For lists of detected and suppressed errors, rerun with: -s
- ==166== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
- ==165== LEAK SUMMARY:
- ==165== definitely lost: 0 bytes in 0 blocks
- ==165== indirectly lost: 0 bytes in 0 blocks
- ==165== possibly lost: 0 bytes in 0 blocks
- ==165== still reachable: 1,081 bytes in 5 blocks
- ==165== suppressed: 0 bytes in 0 blocks
- ==165== Rerun with --leak-check=full to see details of leaked memory
- ==165==
- ==165== For lists of detected and suppressed errors, rerun with: -s

# Requierment
- General
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)

# Testing code
- Your shell should work like this in interactive mode:
- $ ./hsh
- ($) /bin/ls
- hsh main.c shell.c
- ($)
- ($) exit
- $

But also in non-interactive mode:
- $ echo "/bin/ls" | ./hsh
- hsh main.c shell.c test_ls_2
- $
- $ cat test_ls_2
- /bin/ls
- /bin/ls
- $
- $ cat test_ls_2 | ./hsh
- hsh main.c shell.c test_ls_2
- hsh main.c shell.c test_ls_2
- $

# Exemple usage
- root@9e07271f045e4bdfa379799071e5c5c9-2377118072:/holbertonschool-simple_shell# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 build.c exevce.c free.c getenv.c path.c read.c shell.h simple_shell.c strdup.c token.c -o hsh
- root@9e07271f045e4bdfa379799071e5c5c9-2377118072:/holbertonschool-simple_shell# ./hsh
- $ ls
- README.md build.c exevce.c free.c getenv.c hsh man_page.c path.c read.c shell.h simple_shell.c strdup.c token.c
- $ ls -l
- total 68
- -rw-r--r-- 1 root root 2190 Apr 23 13:32 README.md
- -rw-r--r-- 1 root root 1453 Apr 23 13:32 build.c
- -rw-r--r-- 1 root root 844 Apr 23 13:32 exevce.c
- -rw-r--r-- 1 root root 321 Apr 23 13:32 free.c
- -rw-r--r-- 1 root root 709 Apr 23 13:32 getenv.c
- -rwxr-xr-x 1 root root 17464 Apr 23 14:56 hsh
- -rw-r--r-- 1 root root 856 Apr 23 13:32 man_page.c
- -rw-r--r-- 1 root root 996 Apr 23 13:32 path.c
- -rw-r--r-- 1 root root 454 Apr 23 13:32 read.c
- -rw-r--r-- 1 root root 643 Apr 23 13:32 shell.h
- -rw-r--r-- 1 root root 700 Apr 23 13:32 simple_shell.c
- -rw-r--r-- 1 root root 283 Apr 23 13:32 strdup.c
- rw-r--r-- 1 root root 904 Apr 23 13:32 token.c
- $ /bin/ls
- README.md build.c exevce.c free.c getenv.c hsh man_page.c path.c read.c shell.h simple_shell.c strdup.c token.c
- $ /bin/ls -l
- total 68
- -rw-r--r-- 1 root root 2190 Apr 23 13:32 README.md
- -rw-r--r-- 1 root root 1453 Apr 23 13:32 build.c
- -rw-r--r-- 1 root root 844 Apr 23 13:32 exevce.c
- -rw-r--r-- 1 root root 321 Apr 23 13:32 free.c
- -rw-r--r-- 1 root root 709 Apr 23 13:32 getenv.c
- -rwxr-xr-x 1 root root 17464 Apr 23 14:56 hsh
- -rw-r--r-- 1 root root 856 Apr 23 13:32 man_page.c
- -rw-r--r-- 1 root root 996 Apr 23 13:32 path.c
- -rw-r--r-- 1 root root 454 Apr 23 13:32 read.c
- -rw-r--r-- 1 root root 643 Apr 23 13:32 shell.h
- -rw-r--r-- 1 root root 700 Apr 23 13:32 simple_shell.c
- -rw-r--r-- 1 root root 283 Apr 23 13:32 strdup.c
- -rw-r--r-- 1 root root 904 Apr 23 13:32 token.c

# BUGS
No know Bugs

# Flowchart
