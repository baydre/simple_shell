# Simple Shell
This project is about programming a simple Unix shell. A shell is an interactive command-line interpreter that allows users to interact with the operating system by typing commands. We created a shell that would utilize the command line interface (CLI) that allows users to type in a defined set of commands (e.g. **”rm”** to remove files, **”cat"** to combine word documents, etc) and have the operating system run the appropriate function.

The shell is different from a graphical user interface (GUI). Rather than using a mouse to click to open folders and delete files, a user can type in a command (i.e. **"ls"** or  **"rm"**) and have the files be displayed or modified in a list on the command line. GUI and CLI both have the same purpose to interact with the operating system but their input methods are different and some developers prefer the CLI to interact with the shell because their typing is quicker than clicking and dragging.
There are a few versions of Unix shells, from the very first (Ken Thompson's) shell that can be activated by typing <strong>sh</strong> in the terminal to today's most popular Bash (Bourne Again Shell). Later versions of the shell handle memory leaks better and have more functionality. <br>This UNIX shell is a simpler version that handles memory leaks and has basic functionality. It can create, write, read, open, or remove folders, print things to the terminal, change directories, print where you are in the system, etc.

# Background

### Simple UNIX command interpreter.

*“The Gates of Shell”*, by [Yasir Musa](https://twitter.com/baydre_africa), featuring [Ogu Jessica Chidera](https://twitter.com/ogujessica2)

The original Unix operating system was designed and implemented by a team of computer scientists at Bell Labs in the 1970s. The primary contributors to Unix were Ken Thompson, Dennis Ritchie, and others. Ken Thompson is a computer scientist and one of the key figures in the development of Unix and the C programming language. He co-designed and implemented the original Unix operating system and made significant contributions to the field of computer science.
A Unix command line interpreter, also known as a shell, is a program that provides a command-line interface for users to interact with an operating system. When you enter a command in a shell, the shell interprets it and executes the corresponding action. It acts as an intermediary between the user and the operating system, allowing users to run programs, manipulate files, and perform various tasks.

The most commonly used Unix shell is called *Bash* (short for Bourne-Again SHell), but there are other shells available, such as *Zsh*, *Ksh*, and *Csh*. The shell provides a set of built-in commands, such as `cd` (change directory) and `ls` (list directory contents), as well as the ability to execute external programs by specifying their file path or name.

The Unix command line interface is often preferred by advanced users because it allows for more powerful and efficient interaction with the system compared to graphical user interfaces. It also provides access to a wide range of powerful Unix utilities and tools that can be combined and piped together to perform complex tasks.

# Objectives

The objective of this project is to write a UNIX command line interpreter with the following features:
- Display an executable prompt and wait for the user to type a command ending with a new line.
- Handle command lines with arguments, `PATH` implements `exit` and `env` built-ins.
- custom getline function, implements setenv, unsetenv, cd and PWD.
- Handle the commands separator ```;```, Logical Operators ```&& and ||```, and implement alias built-in commands.
- Handle variable replacement ```$? , $$``` variables, comments ```#```

# Concepts
- Working Process of a Shell
- PID & PPID
- Arguments
- Environment variables
- Executing a program
- Creating processes
- Fork + Wait + execve

**Read:**
[Basic concepts you need to know to start coding a UNIX command interpreter.](https://gist.github.com/baydre/d1b96963c09204ff9356624bceb3ce4f)

# Compilation
The shell was compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
# Testing
The shell works like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
And also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
