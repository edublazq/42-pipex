/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:34:11 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/21 16:34:12 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

# define ARGC 2

typedef struct s_pipe
{
	char	**cmd[2];
	int		fd[2];
	char	**path;
}	t_pipe;

void	error_msg(char *msg, int exit_code);
void	free_error(void *toclean, char *msg, int exit_code);
void	*free_pipex(t_pipe *pipex);

#endif