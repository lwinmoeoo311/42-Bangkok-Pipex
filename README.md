*This project has been created as part of the 42 curriculum by lwoo*

## Description

Pipex project wants you to understand pipe, the processes, and how to connect parent process and child process by using pipe.

- Process creation with fork()
- Inter-process communication using pipe()
- File descriptor redirection via dup2()
- Command execution with execve()
- Error handling and PATH resolution

## Instruction

### Compilation

Compile the project using the provided Makefile:
- make

To compile the project for bonus part:
- make bonus

To clean object files:
- make clean

To clean everything:
- fclean

To recompile:
- make re

To recompile bonus part:
- make re_bonus

### Execution

Basic usage:
- ./pipex infile "cmd1" "cmd2" outfile

Bonus usage with "here_doc":
- ./pipex_bonus here_doc LIMITER "cmd1" "cmd2" ... outfile

## Resources

- man pipe
- man fork
- man dup2
- man execve

Medium link: `https://medium.com/@omimouni33/pipex-the-42-project-understanding-pipelines-in-c-71984b3f2103`

Repo Link: `https://github.com/gabcollet/pipex`

Use of AI
- AI tools were used as a support resource during development for:
- Clarifying the behavior of Unix system calls
- Understanding edge cases related to pipes and file descriptors
- Improving code structure and error handling logic
