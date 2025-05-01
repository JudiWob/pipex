#include "header.h"

char *shorten_path(char *path, char *argv)
{
    int i;
    char *temp;

    temp = path;
    i = 0;
    while(temp[i] != ':')
        i++;
    path = malloc((i + strlen(argv) + 2) * (sizeof(char)));
    if (path == NULL)
        exit(EXIT_FAILURE);
    i = 0;
    while(temp[i] != ':' && temp[i])
    {   
        path[i] = temp[i];
        i++;
    }
    path[i] = '/';
    return (path);
}


char *get_path(char *argv, char **envp)
{
    char *path;
    int i;

    path = NULL;
    i = 0;
    while(envp[i])
    {
        if (strncmp(envp[i], "PATH=", 5) == 0) 
        path = (envp[i] + 5);
        i++;
    }
    if (path == NULL)
    {
        printf("Could not find ""PATH="" "); /// !!!!!!!!!!! printf
        exit(EXIT_FAILURE);
    }
    path = shorten_path(path, argv);
    strcat(path, argv); 
    
    path = "/bin/ls";
    printf("Found PATH: %s\n", path); // +5 skips "PATH="
    if(access(path, X_OK) != 0)
    {
        printf("Error: %s: cmd could not be found", argv); /// !!!!!!!!!!! printf
        exit(EXIT_FAILURE);
    }
    
    return path;
}

int main(int argc, char **argv, char **envp)
{
    char *path;

    path = get_path(argv[1], envp);
    
    printf("%s\n", path);

}