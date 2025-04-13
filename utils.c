#include <header.h>

char *get_path(char **argv, char **envp)
{
    int i = 0;

    while(envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0) {
            //printf("Found PATH: %s\n", envp[i] + 5); // +5 skips "PATH="
            return(envp[i] + 5);
        }
        i++;
    }
    return NULL;
}


// int main(int argc, char **argv, char **envp)
// {
//     char *path;

//     path = get_path(&argv[1], envp);
    
//     printf("%s\n", path);

// }