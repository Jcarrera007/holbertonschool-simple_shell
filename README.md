README.md
markdown
Copy code
# hsh — Holberton School Simple Shell

A lightweight UNIX command interpreter written in C for educational purposes.  

## Features

- **Interactive Prompt**: Displays current directory and custom `$ ` prompt.  
- **Non-Interactive Mode**: Reads commands from pipe or file, then exits.  
- **Built-in Commands** (no fork):
  - `exit [status]` — Exit shell with optional status code.  
  - `env` — Print current environment.  
  - `cd [dir]` — Change directory (defaults to `$HOME`).  
  - `pid` — Print shell’s PID.  
  - `pwd` — Print working directory.  
  - `ls [dir]`, `cat [file]`, `joke` — Additional fun built-ins.  
- **External Execution**: Searches `$PATH`, spawns child with `fork()` + `execve()`.  
- **Error Handling**: Matches `/bin/sh` style (`<prog>: <line>: <cmd>: not found`).  
- **Signal Handling**: Ignores Ctrl+C in shell, forwards to child processes.  
- **Memory Safe**: No leaks (Valgrind-tested).  

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
