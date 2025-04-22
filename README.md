# pipex

## 👩‍💻 Progress

22.04 Almost ready for validation, testing phase

## 💡 Overview

This project is a simplified version of the Unix pipe mechanism, recreated as part of the 42 school curriculum.
It demonstrates the use of file descriptors, process creation, and piping output from one command into another.

## ✅ Objective

Reproduce the following shell command in C:

$ <infile cmd1 | cmd2 >outfile

## ✅ Usage

$ ./pipex infile "cmd1" "cmd2" outfile
• file1 and file2 are file names.
• cmd1 and cmd2 are shell commands with their parameters.

Example:
$ ./pipex file1.txt "grep hello" "wc -l" file2.txt
equivalent to
$ < file1.txt grep hello | wc -l > file2.txt

## ✅ Allowed functions
open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid




