# holbertonschool-simple_shell

# Simple Shell

This is a simple UNIX shell written in C. It provides basic functionality to execute commands, handle environment variables, and includes some built-in commands.

## Features

- Interactive and non-interactive modes
- Execution of external commands from PATH
- Built-in commands: `exit` and `env`
- Environment variable handling

## Installation

To compile the shell, simply run the following command:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
