/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:28:31 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/01 16:24:41 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_argc(int argc);
int		create_fork(t_struct *fds);
void	open_pipe(t_struct *fds);
int		open_infile(char *infilename, int flags, t_struct *fds);
int		open_outfile(char *outfilename, int flags, mode_t mode, t_struct *fds);

void	check_argc(int argc)
{
	if (argc != 5)
	{
		stderr_printf("%s", "Error: usage: infile cmd1 cmd2 outfile");
		exit(EXIT_FAILURE);
	}
}

int	create_fork(t_struct *fds)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		stderr_printf("Error: fail forking: %s\n", strerror(errno));
		close(fds->infile);
		close(fds->outfile);
		free(fds);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	open_pipe(t_struct *fds)
{
	if (pipe(fds->fd) == -1)
	{
		stderr_printf("Error: fail opening pipe: %s\n", strerror(errno));
		close(fds->infile);
		close(fds->outfile);
		free(fds);
		exit(EXIT_FAILURE);
	}
}

int	open_infile(char *infilename, int flags, t_struct *fds)
{
	fds->infile = open(infilename, flags);
	if (fds->infile < 0)
	{
		stderr_printf("Error: %s:", strerror(errno));
		stderr_printf(" %s \n", infilename);
		close(fds->infile);
		free(fds);
		exit(EXIT_FAILURE);
	}
	return (fds->infile);
}

int	open_outfile(char *outfilename, int flags, mode_t mode, t_struct *fds)
{
	fds->outfile = open(outfilename, flags, mode);
	if (fds->outfile < 0)
	{
		stderr_printf("Error: %s:", strerror(errno));
		stderr_printf(" %s\n: ", outfilename);
		close(fds->infile);
		close(fds->infile);
		free(fds);
		exit(EXIT_FAILURE);
	}
	return (fds->outfile);
}
