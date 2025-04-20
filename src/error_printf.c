#include "header.h"

void stderr_putchar(int c)
{
	write(2, &c, 1);
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

// int main()
// {   
//     FILE *f = fopen("nonexistent.txt", "r");
// 	if (!f)
// 		stderr_printf("Error: %s\n", strerror(errno));
//     return 0;
// }