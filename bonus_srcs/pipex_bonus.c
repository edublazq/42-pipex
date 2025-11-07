/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:03:31 by bamberger12       #+#    #+#             */
/*   Updated: 2025/11/04 12:03:31 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	init_pipex(int ac, char **av, char **env, t_pipex *pipex)
{
	size_t	i;

	set_number(ac, av, pipex);
	pipex->prev_fd = -1;
	i = 0;
	while (i < pipex->nb)
	{
		pipex->cmd[i] = ft_split(av[i + 2 + pipex->here_doc], ' ');
		i++;
	}
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			pipex->path = ft_split(env[i] + 5, ':');
			set_path(pipex);
			break ;
		}
		i++;
	}
	if (!env[i] || !pipex->path)
		free_exit(pipex, "Couldn't find $PATH", 3);
	set_fd(ac, av, pipex);
}

static void	new_child(t_pipex *pipex, int *fd_pipe, size_t i, char **env)
{
	pipex->child[i] = fork();
	if (pipex->child[i] == 0)
	{
		if (i == 0)
			dup2_manager(fd_pipe[1], pipex->fd[0], pipex);
		else if (i == pipex->nb - 1)
			dup2_manager(pipex->fd[1], pipex->prev_fd, pipex);
		else
			dup2_manager(fd_pipe[1], pipex->prev_fd, pipex);
		if (i != 0)
			close(pipex->prev_fd);
		close_pipes(pipex->fd);
		close_pipes(fd_pipe);
		execve(search_cmd(pipex->cmd[i][0], pipex), pipex->cmd[i], env);
	}
	else if (pipex->child[i] < 0)
		free_exit(pipex, "Child error: ", 1);
	else
		return ;
}

static void	proc(t_pipex *pipex, char **env)
{
	int		fd_pipe[2];
	size_t	i;

	i = 0;
	while (i < pipex->nb)
	{
		pipe(fd_pipe);
		new_child(pipex, fd_pipe, i, env);
		close(pipex->prev_fd);
		pipex->prev_fd = fd_pipe[0];
		close(fd_pipe[1]);
		i++;
	}
	close(fd_pipe[0]);
	close(pipex->prev_fd);
	i = 0;
	while (i < pipex->nb)
		waitpid(pipex->child[i++], NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	int		heredoc;

	if (ac < 5)
		exit_error("Not enough arguments", 1);
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		exit_error("malloc fail: ", 1);
	init_pipex(ac, av, env, pipex);
	proc(pipex, env);
	heredoc = 0;
	if (pipex->here_doc == 1)
		heredoc = pipex->here_doc;
	free_pipex(pipex);
	if (heredoc)
		unlink(".heredoc");
	return (0);
}
