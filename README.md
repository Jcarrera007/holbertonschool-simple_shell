# Simple Shell Project

This project is a simple UNIX command-line interpreter, also known as a shell. It mimics basic functionalities of traditional UNIX shells like `sh` or `bash`, including executing commands, managing processes, and interacting with the environment.

## 📚 Background Concepts

### 🧠 History & Key Figures

- **Who designed and implemented the original Unix operating system?**  
  Ken Thompson and Dennis Ritchie at Bell Labs in the late 1960s and early 1970s.

- **Who wrote the first version of the UNIX shell?**  
  Stephen R. Bourne wrote the first widely used UNIX shell, known as the Bourne shell (`sh`).

- **Who invented the B programming language (the direct predecessor to the C programming language)?**  
  Ken Thompson developed the B language, which led to the development of C by Dennis Ritchie.

- **Who is Ken Thompson?**  
  A computer scientist known for co-creating the UNIX operating system, the B programming language, and early contributions to computer science and security.

---

### 🖥️ How Does a Shell Work?

A shell reads user input, parses it into commands and arguments, locates the executable using the `PATH` environment variable, and uses system calls like `fork()` and `execve()` to create a new process and execute the command.

---

### 🔢 PID and PPID

- **PID (Process ID)**: A unique number assigned to a running process by the operating system.
- **PPID (Parent Process ID)**: The process ID of the process that created (or forked) the current process.

You can retrieve these values using system calls:
```c
pid_t pid = getpid();   // Gets current process ID
pid_t ppid = getppid(); // Gets parent process ID
```

---

### 🌍 Manipulating the Environment

You can access and modify the environment using:
- `getenv()` – Retrieve environment variable
- `setenv()` – Set or update an environment variable
- `unsetenv()` – Remove an environment variable

These allow a shell to read `PATH`, `HOME`, etc., and adjust behavior accordingly.

---

### ⚙️ Function vs System Call

- **Function**: A reusable block of code in user space, often part of a library.
- **System Call**: A function that requests a service from the operating system kernel (e.g., `execve`, `fork`, `read`, `write`).

---

### 👶 Creating Processes

The `fork()` system call creates a new child process. It returns:
- `0` to the child
- Child’s PID to the parent
- `-1` if an error occurred

```c
pid_t pid = fork();
```

---

### 📝 Prototypes of `main`

C programs may define `main` using any of the following prototypes:
```c
int main(void);
int main(int argc, char *argv[]);
int main(int argc, char **argv);
```

---

### 🔍 Using PATH

The shell searches each directory in the `PATH` environment variable for the command. If found, it uses `execve()` to run it.

---

### 🚀 Executing Programs with `execve`

`execve` replaces the current process image with a new process image.

```c
execve("/bin/ls", args, environ);
```

---

### ⏳ Waiting for Children

To wait until a child process finishes, use `wait()` or `waitpid()`:

```c
int status;
pid_t child_pid = wait(&status);
```

---

### ⛔ EOF (End-of-File)

EOF signifies no more input. It's often triggered by:
- `Ctrl+D` on UNIX/Linux
- `feof(stdin)` or checking for `read()` returning `0`

---

## 🛠️ Features of This Shell

- Prints a prompt
- Tokenizes input
- Handles built-in and external commands
- Manages environment variables
- Uses `fork()` and `execve()` to execute processes
- Handles process termination with `wait()`
- Interprets EOF and handles exit gracefully

---

## 🧑‍💻 Authors.

- <a href="https://github.com/Jcarrera007">Jimmy Carrera</a>
- <a href="https://github.com/victor10days">Victor Diaz</a>

---

## 📄 License

This project is released under the MIT License.

