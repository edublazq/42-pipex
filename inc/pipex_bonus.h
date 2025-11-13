/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:04:07 by bamberger12       #+#    #+#             */
/*   Updated: 2025/11/04 12:04:08 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		here_doc;
	int		prev_fd;
	size_t	nb;
	char	***cmd;
	int		fd[2];
	char	**path;
	pid_t	*child;
}	t_pipex;

//CHILDS
void	close_pipes(int	*pipe);
void	dup2_manager(int fd_stdout, int fd_stdin, t_pipex *pipex);
void	free_child(t_pipex *pipex);

//UTILS
void	set_number(int ac, char **av, t_pipex *pipex);
void	set_fd(int ac, char **av, t_pipex *pipex);
void	set_path(t_pipex *pipex);
char	*search_cmd(char *cmd, t_pipex *pipex);

//ERRORS
void	infile_error(t_pipex *pipex);
void	freedom(void *to_free);
void	exit_error(char *msg, int exit_code);
void	free_pipex(t_pipex *pipex);
void	free_exit(void *to_free, char *msg, int exit_code);

#endif
