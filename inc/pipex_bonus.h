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
	int		nb;
	char	***cmd;
	int		fd[2];
	char	**path;
	pid_t	*child;
}	t_pipex;

//CHILDS
void	set_number(int ac, char **av, t_pipex *pipex);

//ERRORS
void	exit_error(char *msg, int exit_code);
void	free_exit(void *to_free, char *msg, int exit_code);

#endif
