/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:28:24 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/01 16:24:00 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv, char **envp)
{
	t_struct	*fds;
	pid_t		pid1;
	pid_t		pid2;

	check_argc(argc);
	fds = malloc(sizeof(t_struct));
	if (!fds)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	fds->infile = open_infile(argv[1], O_RDONLY, fds);
	fds->outfile = open_outfile(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644,
			fds);
	open_pipe(fds);
	pid1 = create_fork(fds);
	if (pid1 == 0)
		child(1, fds, argv[2], envp);
	pid2 = create_fork(fds);
	if (pid2 == 0)
		child(2, fds, argv[3], envp);
	close_fds(fds);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
