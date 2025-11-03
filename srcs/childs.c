/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:38:49 by edblazqu          #+#    #+#             */
/*   Updated: 2025/11/03 11:38:50 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	dup2_manager(int fd_stdout, int fd_stdin, t_pipe *pipex)
{
	if (dup2(fd_stdout, STDOUT_FILENO) == -1)
		free_error(pipex, "dup2 error: ", 1);
	if (dup2(fd_stdin, STDIN_FILENO) == -1)
		free_error(pipex, "dup2 error: ", 1);
}

void	close_pipe(int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
}
