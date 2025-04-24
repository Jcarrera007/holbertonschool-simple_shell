# hsh – A Simple UNIX Shell

`hsh` is a minimalist UNIX command interpreter written in C, built for educational purposes under strict constraints:
- **Language**: C (GNU89)
- **Style**: Betty‐compliant
- **Memory Safety**: No leaks (Valgrind‐tested)
- **Modularity**: ≤5 functions per file
- **Allowed Calls**: `fork`, `execve`, `waitpid`, `stat`, `getcwd`, `getline`, `isatty`, and string/I/O routines.

## Features

- Interactive prompt with current directory and Jovani Vázquez quotes.
- Executes built‐in commands:
  - `cd [dir]` – change directory
  - `exit` – exit shell
  - `env` – print environment
  - `pid` – show shell’s PID
- External commands via `PATH` lookup (or absolute/relative paths).
- Robust error messaging matching `/bin/sh`.
- Handles EOF (Ctrl+D) and interrupts (Ctrl+C).
- Non-interactive mode: suppresses prompts and banners, returns correct exit codes (127 on “not found”).
