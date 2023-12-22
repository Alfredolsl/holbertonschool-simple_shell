# Simple Shell

Simple bash-like shell using C code, pseudo-recreation of the
`sh` command.

## Description

Simple shell that uses C code as its base,
includes basic command line intepretation and basic built-ins.

## Files

| Name | Description |
| ------------------------------ | -------------------------------------------- |
| shell.h | Header file program. |
| main.c | Main function, interactive and non-interactive. |
| forking.c | Function that creates a new process. |
| own_cd.c | Change the working directory. |
| own_env.c | Function that prints environment variables. |
| own_exit.c | Exit shell with a given state. |
| own_help.c | Function that prints help (get information about a command) |
| readline.c | Read a line from stdin. |
| readstream.c | Read a line from the stream. |
| interactive_mode.c | Run shell interactive mode. |
| noninteractive_mode.c | Run shell non-interactive mode. |
| splitline.c | Splits string into tokens. |
| exec_args.c | Number of builtin functions. |

## Usage
To execute interactive mode: ```./hsh```

To execute non-interactive mode: ```echo [command] | ./hsh```

### Example
Run shell in interactive mode:

```
 ./hsh
hsh$ ls
```

Run shell in non-interactive mode

```
 echo ls -l | ./hsh
```

## How to install

Clone this repo and compile with this command:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
