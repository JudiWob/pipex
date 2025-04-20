#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>


#define EXIT_FAILURE 1
#define EXIT_SUCESS 0

#define READ_END 0
#define WRITE_END 1

//set up
void    check_argc(int argc);
int     open_infile(char *filename, int flags);
int     open_outfile(char *filename, int flags, mode_t mode, int infile);
void    open_pipe(int *fd, int infile, int outfile);
int     create_fork();
void    child_1(int infile, int outfile, int *fd, char *argv, char **envp);
void    child_2(int infile, int outfile, int *fd, char *argv, char **envp);

void    stderr_printf(char *s, char *strerror);
char    *get_path(char *argv);
char    *get_path2(char *argv);
char    **ft_split(char const *s, char c);
#endif