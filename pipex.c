/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:34:06 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/21 16:34:06 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_path(t_pipe *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->path[i])
	{
		ft_strlcat(pipex->path[i], "/", 100);
		i++;
	}
}

static t_pipe	*parse_pipe(char **av, char **env, t_pipe *pipex)
{
	size_t	i;

	pipex->fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd[1] == -1)
		free_error(pipex, "File descriptor error 2", 3);
	pipex->fd[0] = open(av[1], O_RDONLY);
	if (pipex->fd[0] == -1)
		free_error(pipex, "File descriptor error 1", 3);
	pipex->cmd[0] = ft_split(av[2], ' ');
	pipex->cmd[1] = ft_split(av[3], ' ');
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
	if (!(env[i]))
		free_error(pipex, "Couldn't find $PATH", 3);
	return (pipex);
}

char	*search_cmd(char *cmd, t_pipe *pipex)
{
	char	*route;
	size_t	i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (pipex->path[i])
	{
		route = ft_strjoin(pipex->path[i], cmd);
		if (access(route, X_OK) == 0)
			break ;
		free(route);
		route = NULL;
		i++;
	}
	if (!route)
		free_error(pipex, "Couldn't find the command in $PATH ", 1);
	return (route);
}

void	process(t_pipe *pipex, char **env)
{
	pid_t	child[2];
	int		fd_pipe[2];

	child[0] = fork();
	if (child[0] == 0 && !pipe(fd_pipe))
	{
		dup2(fd_pipe[1], STDOUT_FILENO);
		dup2(pipex->fd[0], STDIN_FILENO);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
		execve(search_cmd(pipex->cmd[0][0], pipex), pipex->cmd[0], env);
	}
	else if (child[0] > 0)
	{
		child[1] = fork();
		if (child[1] == 0)
		{
			waitpid(child[0], NULL, 0);
			dup2(fd_pipe[0], STDIN_FILENO);
			dup2(pipex->fd[1], STDOUT_FILENO);
			close(fd_pipe[1]);
			close(fd_pipe[0]);
			execve(search_cmd(pipex->cmd[1][0], pipex), pipex->cmd[1], env);
		}
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipe	*pipex;

	if (ac != 5)
	{
		ft_putstr_fd("Usage: infile command1 command2 outfile", 2);
		exit(1);
	}
	pipex = ft_calloc(1, sizeof(t_pipe));
	if (!pipex)
		exit(1);
	pipex = parse_pipe(av, env, pipex);
	if (!pipex)
		free_error(pipex, "error on pipex: ", 1);
	process(pipex, env);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	free_pipex(pipex);
	return (0);
}
