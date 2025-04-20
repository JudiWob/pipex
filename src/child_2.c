#include "header.h"

void child_2(int infile, int outfile, int *fd, char *argv, char **envp)
{
    char **cmd;
    char *path;
    
    //Read from fd0 and not from stdin
    if(dup2(fd[0], STDIN_FILENO) < 0){
    stderr_printf("Dup2 Error0: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
    }
    //write to outfile and not to stdout
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
    path = get_path2(cmd[0]);
    if (execve(path, cmd, envp) == -1) {
        // If execve fails, print error
        perror("execve failed");
        exit(EXIT_FAILURE);
    }
    
}