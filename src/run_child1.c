#include "header.h"

void run_child1(int infile, int outfile, int *fd, char *argv, char **envp)
{
    char **cmd;
    char *path;
    
    if(dup2(infile, STDIN_FILENO) < 0){
    stderr_printf("Dup2 Error0: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
    }
    //write to the pipe and not to stdout
    if(dup2(outfile, STDOUT_FILENO) < 0){
        stderr_printf("Dup2 Error1: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
        }

    // Close unused file descriptors in the child
    close(fd[0]);  // Close read end of the pipe
    close(fd[1]);
    close(infile);
    close(outfile);

    cmd = ft_split(argv, ' ');
    path = get_path(cmd[0]);
    if (execve(path, cmd, envp) == -1) {
        // If execve fails, print error
        perror("execve failed");
        exit(EXIT_FAILURE);
    }
}
//Read from file, not from stdin
