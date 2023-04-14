# Simple Shell

A simple UNIX command interpreter written in C.

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Commands](#commands)
- [Built-in Commands](#built-in-commands)
- [Exit Status](#exit-status)
- [Authors](#authors)

## Introduction

Simple Shell is a simple UNIX command interpreter that reads commands from either standard input or from a file, and executes them.

This program was written as part of a coding challenge, and may not be suitable for use in production environments.

## Getting Started

## Installation

To build the program, simply run the following commands:

This will build the `shell` executable.

To get started, clone the repository and compile the program using the `gcc` compiler:

```bash
$ git clone https://github.com/Dr-dyrane/simple-shell.git
$ cd simple-shell
$ gcc -Wall -Werror -Wextra -pedantic *.c -o shell
```

## Description

This program implements a basic shell in C language. It provides a simple command-line interface for the user to execute commands. The program reads input from the user and executes the command using the `execve` system call.

## Usage

To use the program, simply run the `shell` executable. The program will display a prompt and wait for user input. Enter a command and press enter to execute the command.

```bash
$ ./shell
```

You will be presented with a prompt that looks like this:

```bash
(sh) $
```

You can then enter commands to execute, either one at a time, or multiple commands on the same line separated by a semicolon:

```bash
(sh) $ ls
file1.txt  file2.txt  file3.txt
(sh) $ pwd; ls
/home/user/simple-shell
file1.txt  file2.txt  file3.txt
```

To exit the program, simply type the `exit` command:

```bash
(sh) $ exit
```

## Commands

The Simple Shell supports a variety of commands, including built-in commands and external commands:

```bash
$ <command> [arguments]
```

## Examples

```bash
$ ls
$ cd /home/user/directory
$ echo "Hello, world!"
```

## Built-in Commands

The Simple Shell also includes some built-in commands:

```txt
cd - Change the current working directory.
exit - Exit the shell.
```

## Examples

```bash
$ cd /home/user/directory
$ exit
```

## Exit Status

The Simple Shell returns an exit status to indicate whether the command was executed successfully or not. If the command was executed successfully, the exit status will be 0. If the command was not executed successfully, the exit status will be a non-zero integer.

## Author

This program was written by Alexander Udeoagaranya [<halodyrane@gmail.com>](https://github.com/Dr-dyrane).

## Aknowledgement

This program is released under the [ALX SE Program](https://https://intranet.alxswe.com/projects/235).
