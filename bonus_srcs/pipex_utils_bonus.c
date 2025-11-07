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

void	set_path(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->path[i] != NULL)
	{
		pipex->path[i] = ft_strjoin_free(pipex->path[i], "/");
		i++;
	}
}

void	set_number(int ac, char **av, t_pipex *pipex)
{
	pipex->nb = ac - 3;
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		pipex->here_doc = 1;
		pipex->nb = ac - 4;
	}
	pipex->child = ft_calloc(pipex->nb, sizeof(pid_t));
	if (!pipex->child)
		free_exit(pipex, "malloc error", 1);
	pipex->cmd = ft_calloc(pipex->nb, sizeof(char **));
	if (!pipex->cmd)
		free_exit(pipex, "malloc error", 1);
}

void	here_doc(char *limit, t_pipex *pipex)
{
	int		tmp_fd;
	char	*gnl;

	if (!limit)
		free_exit(pipex, "Wrong limiter! ", 1);
	tmp_fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex->fd[0] = open(".heredoc", O_RDONLY);
	if (tmp_fd < 0 || pipex->fd[0] < 0)
		free_exit(pipex, "Heredoc file error: ", 1);
	ft_printf("heredoc> ");
	gnl = get_next_line(0);
	while (ft_strncmp(gnl, limit, ft_strlen(gnl) - 1) != 0)
	{
		ft_putstr_fd(gnl, tmp_fd);
		freedom(gnl);
		ft_printf("heredoc> ");
		gnl = get_next_line(0);
	}
	freedom(gnl);
	close(tmp_fd);
}

void	set_fd(int ac, char **av, t_pipex *pipex)
{
	pipex->fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd[1] == -1)
		free_exit(pipex, "File descriptor error 2", 3);
	if (pipex->here_doc == 1)
	{
		here_doc(av[2], pipex);
		return ;
	}
	pipex->fd[0] = open(av[1], O_RDONLY);
	if (pipex->fd[0] == -1)
		free_exit(pipex, "File descriptor error 1", 3);
}

char	*search_cmd(char *cmd, t_pipex *pipex)
{
	char	*route;
	size_t	i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (pipex->path[i] != NULL && cmd != NULL)
	{
		route = ft_strjoin(pipex->path[i], cmd);
		if (access(route, X_OK) == 0)
			break ;
		free(route);
		route = NULL;
		i++;
	}
	if (!route)
		free_exit(pipex, "Couldn't find the command in $PATH ", 1);
	return (route);
}
