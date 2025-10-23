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

#include "pipex.h"

void	error_msg(char *msg, int exit_code)
{
	ft_putstr_fd(msg, 2);
	exit(exit_code);
}

void	free_error(void *toclean, char *msg, int exit_code)
{
	free(toclean);
	error_msg(msg, exit_code);
}

void	*free_pipex(t_pipe *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->path[i])
		free(pipex->path[i++]);
	free(pipex->path);
	i = 0;
	while(pipex->cmd[0][i])
		free(pipex->cmd[0][i++]);
	free(pipex->cmd[0]);
	i = 0;
	while(pipex->cmd[1][i])
		free(pipex->cmd[1][i++]);
	free(pipex->cmd[1]);
	free(pipex);
	return (NULL);
}