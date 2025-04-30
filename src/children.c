/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:28:15 by jpaselt           #+#    #+#             */
/*   Updated: 2025/04/30 16:05:50 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	child(int ch, int infile, int outfile, int *fd, char *argv, char **envp);
void	child_1(int infile, int *fd);
void	child_2(int outfile, int *fd);
void	ft_free(char **cmd, char *path);

void	child(int ch, int infile, int outfile, int *fd, char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	if (ch == 1)
		child_1(infile, fd);
	else
		child_2(outfile, fd);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	close(outfile);
	cmd = ft_split(argv, ' ');
	path = get_path(cmd, "/bin/", 1);
	if (execve(path, cmd, envp) == -1)
	{
		stderr_printf("Error execve for %s:", argv);
		stderr_printf("%s", strerror(errno));
		ft_free(cmd, path);
		exit(EXIT_FAILURE);
	}
}

void	child_1(int infile, int *fd)
{
	// Read from file, not from stdin
	if (dup2(infile, STDIN_FILENO) < 0)
	{
		stderr_printf("Dup2 Error0: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	// write to the pipe and not to stdout
	if (dup2(fd[1], STDOUT_FILENO) < 0)
	{
		stderr_printf("Dup2 Error1: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void	child_2(int outfile, int *fd)
{
	// Read from fd0 and not from stdin
	if (dup2(fd[0], STDIN_FILENO) < 0)
	{
		stderr_printf("Dup2 Error2: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	// write to outfile and not to stdout
	if (dup2(outfile, STDOUT_FILENO) < 0)
	{
		stderr_printf("Dup2 Error3: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void	ft_free(char **cmd, char *path)
{
	int	j;

	j = 0;
	while (cmd && cmd[j])
		j++;
	while (j > 0)
	{
		free(cmd[j - 1]);
		j--;
	}
	free(cmd);
	free(path);
}
