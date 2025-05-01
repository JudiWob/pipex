/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:28:15 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/01 16:31:41 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	child(int ch, t_struct *fds, char *argv, char **envp);
void	child_1(t_struct *fds);
void	child_2(t_struct *fds);
void	ft_free(char **cmd, char *path, t_struct *fds);

void	child(int ch, t_struct *fds, char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	if (ch == 1)
		child_1(fds);
	else
		child_2(fds);
	close(fds->fd[0]);
	close(fds->fd[1]);
	close(fds->infile);
	close(fds->outfile);
	cmd = ft_split(argv, ' ');
	path = get_path(cmd, "/bin/", 1, fds);
	if (execve(path, cmd, envp) == -1)
	{
		stderr_printf("Error execve for %s:", argv);
		stderr_printf("%s", strerror(errno));
		ft_free(cmd, path, fds);
		exit(EXIT_FAILURE);
	}
}

void	child_1(t_struct *fds)
{
	if (dup2(fds->infile, STDIN_FILENO) < 0)
	{
		stderr_printf("Dup2 Error0: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (dup2(fds->fd[WRITE_END], STDOUT_FILENO) < 0)
	{
		stderr_printf("Dup2 Error1: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void	child_2(t_struct *fds)
{
	if (dup2(fds->fd[READ_END], STDIN_FILENO) < 0)
	{
		stderr_printf("Dup2 Error2: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (dup2(fds->outfile, STDOUT_FILENO) < 0)
	{
		stderr_printf("Dup2 Error3: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void	ft_free(char **cmd, char *path, t_struct *fds)
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
	free(fds);
}
