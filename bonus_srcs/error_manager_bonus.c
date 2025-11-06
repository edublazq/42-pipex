/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:14:03 by edblazqu          #+#    #+#             */
/*   Updated: 2025/11/04 12:14:04 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	freedom(void *to_free)
{
	free(to_free);
	to_free = NULL;
}

void	free_pipex(t_pipex *pipex)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (pipex->path[i])
		free(pipex->path[i++]);
	if (pipex->path != NULL)
		free(pipex->path);
	i = 0;
	while (pipex->cmd[i])
	{
		j = 0;
		while (pipex->cmd[i][j])
			freedom(pipex->cmd[i][j++]);
		freedom(pipex->cmd[i]);
		i++;
	}
	freedom(pipex->cmd);
	freedom(pipex->child);
	if (pipex->fd[0] > 0)
		close(pipex->fd[0]);
	if (pipex->fd[1] > 0)
		close(pipex->fd[1]);
	freedom(pipex);
}

void	exit_error(char *msg, int exit_code)
{
	perror(msg);
	exit (exit_code);
}

void	free_exit(void *to_free, char *msg, int exit_code)
{
	free_pipex(to_free);
	exit_error(msg, exit_code);
}
