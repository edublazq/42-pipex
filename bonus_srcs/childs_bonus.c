/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:38:09 by edblazqu          #+#    #+#             */
/*   Updated: 2025/11/05 11:38:11 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	close_pipes(int	*pipe)
{
	close(pipe[0]);
	close(pipe[1]);
}

void	dup2_manager(int fd_stdout, int fd_stdin, t_pipex *pipex)
{
	if (dup2(fd_stdout, STDOUT_FILENO) == -1)
		free_exit(pipex, "dup2 error: ", 1);
	if (dup2(fd_stdin, STDIN_FILENO) == -1)
		free_exit(pipex, "dup2 error: ", 1);
}

void	free_child(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->path[i])
		freedom(pipex->path[i++]);
	if (pipex->path != NULL)
		free(pipex->path);
	freedom(pipex->child);
	freedom(pipex);
}
