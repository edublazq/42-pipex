/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:40:52 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/21 16:40:54 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	infile_error(t_pipe *pipex)
{
	perror("infile: ");
	pipex->fd[0] = open("/dev/null", O_RDONLY);
	if (pipex->fd[0] < 0)
		free_error(pipex, "Fd error: ", 2);
}

void	*free_pipex(t_pipe *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->path[i])
		free(pipex->path[i++]);
	free(pipex->path);
	i = 0;
	while (pipex->cmd[0][i])
		free(pipex->cmd[0][i++]);
	free(pipex->cmd[0]);
	i = 0;
	while (pipex->cmd[1][i])
		free(pipex->cmd[1][i++]);
	free(pipex->cmd[1]);
	free(pipex);
	pipex = NULL;
	return (NULL);
}

void	*free_error(void *toclean, char *msg, int exit_code)
{
	perror(msg);
	if (exit_code == 3)
	{
		free(toclean);
		toclean = NULL;
		exit(exit_code);
	}
	free_pipex(toclean);
	exit(exit_code);
}
