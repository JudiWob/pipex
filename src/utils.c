#include "header.h"

int create_fork()
{
    int pid1;

    pid1 = fork();
    if(pid1 < 0){
        stderr_printf("Error: forking: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
        //close files?
    }
    return(pid1);
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

char *get_path(char *argv)
{
    const char *prefix = "/bin/";
    int prefix_len = strlen(prefix);
    int cmd_len = strlen(argv);
    
    // +1 for null terminator
    char *path = malloc(prefix_len + cmd_len + 1);
    if (!path)
        return NULL;

    // Copy "/bin/" into path
    strcpy(path, prefix);

    // Append the command name
    strcat(path, argv);
    printf("manual %s\n", path);
    //printf("getpath() %s\n", get_path("wc"));
  
    if(access(path, X_OK) != 0)
    {
        printf("Error: %s: cmd could not be found", argv); /// !!!!!!!!!!! printf
        exit(EXIT_FAILURE);
    }
    return path;
}

// int main(int argc, char **argv, char **envp)
// {
//     char *path;

//     path = get_path(argv[1]);
    
//     

// }