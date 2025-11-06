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
			printf("LLEGO HASTA AQUI\n");
			pipex->path = ft_split(env[i] + 5, ':');
			printf("SPLIT HECHO");
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
		dup2_manager(fd_pipe[PIPE_READ], fd_pipe[PIPE_WRITE], pipex);
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

	pipe(fd_pipe);
	dup2(pipex->fd[0], fd_pipe[PIPE_WRITE]);
	dup2(pipex->fd[1], STDOUT_FILENO);
	i = 0;
	while (i < pipex->nb)
	{
		new_child(pipex, fd_pipe, i, env);
		i++;
	}
	close_pipes(fd_pipe);
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
	heredoc = 0;
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		exit_error("malloc fail: ", 1);
	init_pipex(ac, av, env, pipex);
	proc(pipex, env);
	if (pipex->here_doc == 1)
		heredoc = pipex->here_doc;
	free_pipex(pipex);
	if (heredoc)
		unlink(".heredoc"); 
	return (0);
}
