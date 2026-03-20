# Minishell — As beautiful as a shell

A lightweight Unix shell written in C, built as part of the 42 curriculum. Minishell replicates core Bash behaviors including pipes, redirections, environment variables, signals, and built-in commands.

---

## Features

### Prompt & History
- Displays a custom prompt: `➜ Minishell $>`
- Command history via readline

### Command Execution
- Resolves executables from `PATH`, or via relative/absolute paths
- Forks and executes external commands with `execve`

### Redirections
| Operator | Behavior |
|----------|----------|
| `<`      | Redirect stdin from file |
| `>`      | Redirect stdout to file (overwrite) |
| `>>`     | Redirect stdout to file (append) |
| `<<`     | Heredoc — read until delimiter |

### Pipes
- Chains commands: `cmd1 | cmd2 | cmd3`
- Each segment runs in its own child process

### Quoting
- `'single quotes'` — prevents all interpretation
- `"double quotes"` — prevents interpretation except `$`

### Variable Expansion
- `$VARIABLE` — expands to its value
- `$?` — expands to the exit status of the last command

### Signals
| Signal   | Interactive behavior |
|----------|---------------------|
| `Ctrl-C` | Displays a new prompt on a new line |
| `Ctrl-D` | Exits the shell |
| `Ctrl-\` | Does nothing |

### Built-in Commands
| Command     | Description |
|-------------|-------------|
| `echo [-n]` | Print text, `-n` suppresses trailing newline |
| `cd [path]` | Change directory (relative or absolute) |
| `pwd`       | Print current working directory |
| `export`    | Set or export environment variables |
| `unset`     | Remove environment variables |
| `env`       | Display all environment variables |
| `exit`      | Exit the shell with an optional status code |

---

## Project Structure

```
Minishell/
├── main.c
├── includes/
│   └── minishell.h          # All structs, enums, and prototypes
├── parsing/                 # Tokenization, expansion, error checking
├── builtins/                # Built-in command implementations
├── env_var/                 # Environment variable management
├── exec/                    # Execution, pipes, redirections, signals
└── libft/                   # Custom C utility library
```

---

## Build

```bash
make        # Build the minishell binary
make clean  # Remove object files
make fclean # Remove all build artifacts
make re     # Rebuild from scratch
```

**Dependencies:** `readline` library

---

## Usage

```bash
./minishell
```

```
➜ Minishell $> echo "Hello, World!"
Hello, World!
➜ Minishell $> export NAME=42
➜ Minishell $> echo $NAME
42
➜ Minishell $> ls | grep .c | wc -l
5
➜ Minishell $> cat < file.txt >> output.txt
➜ Minishell $> exit
```

---

## Implementation Notes

- Uses a **garbage collector** for centralized memory management
- One global variable used exclusively to store received signal numbers
- Memory leaks from `readline` are expected and not required to be fixed — all other allocations are properly freed
- Undefined behavior and norm violations are not tolerated

---

## Authors

Built at 42 school.
