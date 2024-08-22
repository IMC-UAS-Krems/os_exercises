# Linux basics

## Introduction

This is a short introduction to basic Linux usage/commands from the user perspective. In this course, we will mainly work with the *command line*, also called *console*, and specifically, with the `bash` shell. This shell is used to type in commands and check their output. Console input is normally called *standard input* and its output correspondingly *standard output*.

We will mainly work with the *Ubuntu* distribution as a reference, but you can work in principle with any distribution that you want.

## First steps

In order to begin working with the shell, the first step is to open a terminal window.

- In Windows: Use *Windows Terminal* and open a new Ubuntu tab.
- In Linux: In the desktop, right click on any empty area and select *Open terminal*.

A prompt of the form `username@hostname:` will appear.

- `username`: The name of the currently logged in user.
- `hostname`: The network name of the machine.

Additionally, the current working directory is also displayed in the prompt. The symbol `~` denotes the *home directory*. Each user has a home directory with unlimited read and write rights. The working directory of the `root` user is commonly `/root` and that of the other users is `/home/username`. 

You can return at any time to your home directory using the command:

```
cd ~
```
You can also print the current directory using the command `pwd`.

```
root@ubuntu:~/src# pwd
/root/src
```
Here a few basic commands for files/directories. You can always get help by accessing the *man page* of any command with the following syntax:
```
man pwd
```
(Quit pressing the 'q' key)

- `mkdir`: Create directory.
- `cp`: Copy file.
- `rm`: Remove file or directory.
- `touch`: Create empty file.
- `cat`: Output the contents of a text file.
- `cd`: Change current directory.
- `ls`: List the contents of a directory.

Text files can be created and edited by using VSCode or any other text editor (like `vi` or `emacs`).

## Some important terminal features

The Linux `bash` shell is a very versatile tool to deal with the command line. There are two funtions that are particularly usedful: the *redirect* and the *pipe* operator.

### Redirecting output

Instead of showing the output of a command in the terminal, you can redirect it to any file by using the following systax:

```
man pwd > pwd.txt
```
This will redirect the output of the `man pwd` command to the newly created file `pwd.txt`.

### Pipe operator

The pipe operator is used to concatenate the output of a command with the input of another command. For instance, before we created a text file `pwd.txt` with the output of the `man` command. If you enter the following command:
```
cat pwd.txt
```
you won't be able to read the whole output since it is longer than a terminal page. So let's concatenate the output of the `cat` command with `less`, which lets you scroll through the contents.
```
cat pwd.txt | less
```
One important usage of the pipe operator is to search for certain lines in a text file/output using the `grep` command. This command allows you to use regular expressions to find occurrences of a given string. Example:

```
cat pwd.txt | grep 'Written by'
```






