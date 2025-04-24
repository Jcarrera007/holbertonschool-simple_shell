# 🐚 hsh — Holberton School Simple Shell

[![C](https://img.shields.io/badge/C-gnu89-blue.svg)](https://gcc.gnu.org/)
[![Shell](https://img.shields.io/badge/Shell-Project-green.svg)](#)
[![Valgrind-Tested](https://img.shields.io/badge/Memory%20Safe-Valgrind-tested-brightgreen.svg)](https://valgrind.org/)

**hsh** 
  -is a lightweight UNIX command-line interpreter written in **C**. It was developed for the Holberton School curriculum to explore the inner workings of a shell, including process creation, signal handling, memory management, and more.

---

## ✨ Features

- **Interactive Mode**  
  Displays the current working directory and a custom `$ ` prompt.

- **Non-Interactive Mode**  
  Executes commands from piped input or a script, then exits.

- **Built-in Commands (without forking):**
  - `exit [status]` – Exit the shell with an optional status code.
  - `env` – Display the current environment.
  - `cd [dir]` – Change the working directory (defaults to `$HOME`).
  - `pid` – Show the shell's process ID.
  - `pwd` – Print the current directory path.
  - `ls [dir]`, `cat [file]`, `joke` – Extra built-in tools and fun.

- **External Commands**  
  Searches `$PATH`, then uses `fork()` + `execve()` to run binaries.

- **Error Handling**  
  Matches `/bin/sh` style:
  ```bash
  hsh: <line_number>: <command>: not found
  ```

- **Signal Handling**  
  Ignores `Ctrl+C` in the shell but correctly forwards to child processes.

- **Memory Safe**  
  Fully tested with Valgrind — no memory leaks.

---

## ⚙️ Compilation

Use the following `gcc` command to compile:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## 🚀 Usage

### 🖥 Interactive Mode:
```bash
./hsh
```
Example prompt:
```
/home/user $
```

### 📄 Non-Interactive Mode:
```bash
echo "ls -l" | ./hsh
```
Or:
```bash
./hsh < script.txt
```

---

## 👥 Authors

- **Jimmy Carrera Otero**  
  [GitHub: Jcarrera007](https://github.com/Jcarrera007)

- **Victor Diaz**  
  [GitHub: victor10days](https://github.com/victor10days)

> Víctor focused on the design and implementation, while Jimmy focused on documentation.

(See the full list in the [AUTHORS](./AUTHORS) file.)

---

## 📝 License

This project is intended for educational purposes only as part of the Holberton School curriculum.

---

## 📎 Resources

- [Holberton School](https://www.holbertonschool.com/)
- [man execve](https://man7.org/linux/man-pages/man2/execve.2.html)
- [Valgrind](https://valgrind.org/)

