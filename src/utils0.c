#include "header.h"

void    check_argc(int argc);
int     create_fork();
void    open_pipe(int *fd, int infile, int outfile);
int     open_infile(char *infilename, int flags);
int     open_outfile(char *outfilename, int flags, mode_t mode, int infile);

void check_argc(int argc)
{
    if(argc != 5)
    {
        stderr_printf("%s", "Error: usage: infile cmd1 cmd2 outfile");
        exit(EXIT_FAILURE);
    }
}

int create_fork()
{
    int pid;

    pid = fork();
    if(pid < 0){
        stderr_printf("Error: forking: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
        //close files?
    }
    return(pid);
}

void open_pipe(int *fd, int infile, int outfile)
{
    if(pipe(fd) == -1){
    stderr_printf("Error opening pipe: %s\n", strerror(errno));
    close(infile);
    close(outfile);
    exit(EXIT_FAILURE);
    }
}

int	open_infile(char *infilename, int flags)
{
	int	infile;

	infile = open(infilename, flags);
	if (infile < 0)
	{
		stderr_printf("Error opening %s: ", infilename);
        stderr_printf("%s\n",strerror(errno));
        close(infile);
		exit(EXIT_FAILURE);
	}
	return (infile);
}


int	open_outfile(char *outfilename, int flags, mode_t mode, int infile)
{
	int	outfile;

	outfile = open(outfilename, flags, mode);
	if (outfile < 0)
	{
		stderr_printf("Error opening %s: ", outfilename);
        stderr_printf("%s\n",strerror(errno));
        close(infile);
        close(outfile);
        exit(EXIT_FAILURE);
	}
	return (outfile);
}