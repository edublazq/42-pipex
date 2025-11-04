/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:40:49 by edblazqu          #+#    #+#             */
/*   Updated: 2025/11/04 12:40:49 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	set_number(int ac, char **av, t_pipex *pipex)
{
	int	nb;

	if (av[1] != "here_doc")
		nb = ac - 3;
	pipex->child = ft_calloc(nb, sizeof(pid_t));
	if (!pipex->child)
		free_exit(pipex, "malloc error", 1);
	pipex->cmd = ft_calloc(nb, sizeof(char **));
	if (!pipex->cmd)
		free_exit(pipex, "malloc error", 1);
	pipex->nb = nb;
}

void	set_fd(int ac, char **av, t_pipex *pipex)
{
	pipex->fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd[1] == -1)
		free_exit(pipex, "File descriptor error 2", 3);ç
	if (av[1] == "here_doc")
	pipex->fd[0] = open(av[1], O_RDONLY);
	if (pipex->fd[0] == -1)
		free_exit(pipex, "File descriptor error 1", 3);
}
