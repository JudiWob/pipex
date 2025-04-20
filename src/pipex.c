#include "header.h"

int main(int argc, char **argv, char **envp)
{
    int     infile, outfile;
    int     fd[2];
    pid_t   pid1, pid2;

    check_argc(argc);
    infile = open_infile(argv[1],  O_RDONLY);
    outfile = open_outfile(argv[4],  O_CREAT | O_WRONLY | O_TRUNC, 0644, infile);
    open_pipe(fd, infile, outfile);
    pid1 = create_fork();
    if(pid1 == 0)
       child(1, infile, outfile, fd, argv[2], envp);

    pid2 = create_fork();
    if(pid2 == 0)
       child(2, infile, outfile, fd, argv[3], envp);

    close_fds(infile, outfile, fd);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

