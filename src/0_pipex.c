#include "header.h"

int main(int argc, char **argv, char **envp)
{

    int fd[2];
    pid_t pid1, pid2;
    int infile, outfile;

    check_argc(argc);
    infile = open_infile(argv[1],  O_RDONLY);
    outfile = open_outfile(argv[4],  O_CREAT | O_WRONLY | O_TRUNC, 0644, infile);
    open_pipe(fd, infile, outfile);
    pid1 = create_fork();

    if(pid1 == 0)
       child_1(infile, outfile, fd, argv[2], envp);

    pid2 = create_fork();
    if(pid2 == 0)
       child_2(infile, outfile, fd, argv[3], envp);

    printf("sucess\n");
}


// int main()
// {
//     int pipefd[2];
//     pid_t pid1, pid2;
//     int infile, outfile;

//     if (argc != 5) 
//         exit(EXIT_FAILURE);

//     infile = open(argv[1], O_RDONLY);
//     if (infile < 0) {
//         stderr_printf("%s\n", strerror(errno));
//         exit(EXIT_FAILURE);
//     }

//     outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
//     if (outfile < 0) {
//         stderr_printf("%s\n", strerror(errno));
//         close(infile);
//         exit(EXIT_FAILURE);
//     }

//     //open pipe
//     if (pipe(pipefd) == -1) {
//         stderr_printf("%s\n", strerror(errno));
//         close(infile);
//         close(outfile);
//         exit(EXIT_FAILURE);
//     }

//     // Fork first child for cmd1
//     pid1 = fork();
//     if (pid1 < 0) {
//         stderr_printf("%s\n", strerror(errno));
//         exit(EXIT_FAILURE);
//     }

//     if (pid1 == 0) // First child process: executes cmd1
//     {  
//         // Redirect standard input to infile
//         if (dup2(infile, STDIN_FILENO) < 0) {
//             stderr_printf("%s\n", strerror(errno));
//             exit(EXIT_FAILURE);
//         }
//         // Write to the pipe and not to stdout
//         if (dup2(pipefd[WRITE_END], STDOUT_FILENO) < 0) {
//             stderr_printf("%s\n", strerror(errno));
//             exit(EXIT_FAILURE);
//         }
        
        
//         //Parent Process closes all descriptors
//         close(infile);
//         close(outfile);
//         close(pipefd[READ_END]);
//         close(pipefd[WRITE_END]);

        


//     }



//     int execve(const char *pathname, char *const argv[], char *const envp[]);


// }



