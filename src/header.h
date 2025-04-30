/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:28:48 by jpaselt           #+#    #+#             */
/*   Updated: 2025/04/30 17:09:01 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define EXIT_FAILURE 1
# define EXIT_SUCESS 0

# define READ_END 0
# define WRITE_END 1

// utils 0
void	check_argc(int argc);
int		create_fork(int infile, int outfile);
void	open_pipe(int *fd, int infile, int outfile);
int		open_infile(char *infilename, int flags);
int		open_outfile(char *outfilename, int flags, mode_t mode, int infile);

// utils1
char	*get_path(char **cmd, char *prefix, int try);
void	stderr_printf(char *s, char *strerror);
void	stderr_putstr(char *s);
void	stderr_putchar(int c);
void	close_fds(int infile, int outfile, int *fd);

// children
void	child(int ch, int infile, int outfile, int *fd, char *argv, char **envp);
void	child_1(int infile, int *fd);
void	child_2(int outfile, int *fd);
void	ft_free(char **cmd, char *path);

#endif