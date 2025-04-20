#include "header.h"

char *get_path(char *argv, char *prefix, int try);
void stderr_printf(char *s, char *strerror);
void stderr_putstr(char *s);
void stderr_putchar(int c);
void close_fds(int infile, int outfile, int *fd);

char *get_path(char *argv, char *prefix, int try)
{
    char *path;
    char *new_path;
    
    path = malloc(ft_strlen(prefix) + ft_strlen(argv) + 1);
    if (!path)
        return NULL;
    ft_strcpy(path, prefix);
    ft_strcat(path, argv);
    if(access(path, X_OK) != 0)
    {
        if(try == 1)
        {
            new_path = get_path(argv, "/usr/bin/", 2);
            return (free(path), new_path);
        } 
        else
        {
            stderr_printf("Error: cmd ""%s"": ", argv);
            stderr_printf("%s", strerror(errno));
            exit(EXIT_FAILURE);            
        }   
    }
    return path;
}

void stderr_printf(char *s, char *strerror)
{
    int i = 0;
    
    while (s[i])
    {
        if (s[i] == '%')
        {
            i++;
            stderr_putstr(strerror);
            i++;
        }
        else
        {
            stderr_putchar(s[i]);
            i++;
        }
    }
}

void stderr_putstr(char *s)
{
    int	i;

    i = 0;
    if (s == NULL)
    {
        stderr_putstr("(null)");
        return;
    }
    while (s[i])
    {
        stderr_putchar(s[i]);
        i++;
    }
    return;
}

void stderr_putchar(int c)
{
	write(2, &c, 1);
}

void close_fds(int infile, int outfile, int *fd)
{
    close(infile);
    close(outfile);
    close(fd[0]);
    close(fd[1]);
}