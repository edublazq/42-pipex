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

	nb = ac - 2;
	if (ft_strcmp(av[1], "here_doc") != 0)
		nb = ac - 3;
	pipex->child = ft_calloc(nb, sizeof(pid_t));
	if (!pipex->child)
		free_exit(pipex, "malloc error", 1);
	pipex->cmd = ft_calloc(nb, sizeof(char **));
	if (!pipex->cmd)
		free_exit(pipex, "malloc error", 1);
	pipex->nb = nb;
}

void	here_doc(char *limit, t_pipex *pipex)
{
	int		tmp_fd;
	int		first;
	char	*gnl;

	if (!limit)
		free_exit(pipex, "Wrong limiter! ", 1);
	pipex->here_doc = 1;
	pipex->fd[0] = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	tmp_fd = pipex->fd[0];
	first = 1;
	gnl = get_next_line(1);
	while (ft_strnstr(gnl, limit, ft_strlen(gnl)) == NULL)
	{
		if (!first)
			gnl = get_next_line(1);
		first = 0;
		ft_putstr_fd(gnl, tmp_fd);
		freedom(gnl);
	}
	freedom(gnl);
	close(tmp_fd);
}

void	set_fd(int ac, char **av, t_pipex *pipex)
{
	pipex->fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd[1] == -1)
		free_exit(pipex, "File descriptor error 2", 3);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		here_doc(av[2], pipex);
		return ;
	}
	pipex->here_doc = 0;
	pipex->fd[0] = open(av[1], O_RDONLY);
	if (pipex->fd[0] == -1)
		free_exit(pipex, "File descriptor error 1", 3);
}
