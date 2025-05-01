/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:28:48 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/01 16:29:41 by jpaselt          ###   ########.fr       */
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
# define EXIT_SUCCESS 0

# define READ_END 0
# define WRITE_END 1

typedef struct s_struct
{
	int	fd[2];
	int	infile;
	int	outfile;
}	t_struct;

// utils 0
void	check_argc(int argc);
int		create_fork(t_struct *fds);
void	open_pipe(t_struct *fds);
int		open_infile(char *infilename, int flags, t_struct *fds);
int		open_outfile(char *outfilename, int flags, mode_t mode, t_struct *fds);

// utils1
char	*get_path(char **cmd, char *prefix, int try, t_struct *fds);
void	stderr_printf(char *s, char *strerror);
void	stderr_putstr(char *s);
void	stderr_putchar(int c);
void	close_fds(t_struct *fds);

// children
void	child(int ch, t_struct *fds, char *argv, char **envp);
void	child_1(t_struct *fds);
void	child_2(t_struct *fds);
void	ft_free(char **cmd, char *path, t_struct *fds);

#endif