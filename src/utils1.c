/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:28:37 by jpaselt           #+#    #+#             */
/*   Updated: 2025/04/30 16:55:05 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_path(char **cmd, char *prefix, int try);
void	stderr_printf(char *s, char *strerror);
void	stderr_putstr(char *s);
void	stderr_putchar(int c);
void	close_fds(int infile, int outfile, int *fd);

char	*get_path(char **cmd, char *prefix, int try)
{
	char	*path;

	path = malloc(ft_strlen(prefix) + ft_strlen(cmd[0]) + 1);
	if (!path)
		return (NULL);
	ft_strcpy(path, prefix);
	ft_strcat(path, cmd[0]);
	if (access(path, X_OK) != 0)
	{
		if (try == 1)
		{
			free(path);
			get_path(&cmd[0], "/usr/bin/", 2);
		}
		else
		{
			stderr_printf("Error: command not found: %s: ", cmd[0]);
			stderr_printf("%s", strerror(errno));
			ft_free(cmd, path);
			exit(EXIT_FAILURE);
		}
	}
	return (path);
}

void	stderr_printf(char *s, char *strerror)
{
	int	i;

	i = 0;
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

void	stderr_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		stderr_putstr("(null)");
		return ;
	}
	while (s[i])
	{
		stderr_putchar(s[i]);
		i++;
	}
	return ;
}

void	stderr_putchar(int c)
{
	write(2, &c, 1);
}

void	close_fds(int infile, int outfile, int *fd)
{
	close(infile);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
}
