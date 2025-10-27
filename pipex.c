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
	size_t	len;
	size_t	i;

	i = 0;
	while (pipex->path[i])
	{
		ft_strlcat(pipex->path[i], "/", 100);
		i++;
	}
}

static void	parse_pipe(char **av, char **env, t_pipe *pipex)
{
	int	i;

	i = 0;
	pipex->fd[0] = open(av[1], O_RDONLY);
	if (pipex->fd[0] == -1)
		free_error(pipex, "File descriptor error 1", 3);
	pipex->fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd[1] == -1)
		free_error(pipex, "File descriptor error 2", 3);
	pipex->cmd[0] = ft_split(av[2], ' ');
	pipex->cmd[1] = ft_split(av[3], ' ');
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
}

char	*search_cmd(char *cmd, t_pipe *pipex)
{
	char	*route;
	size_t	i;
	
	i = 0;
	while (pipex->path[i])
	{
		route = ft_strjoin(pipex->path[i], cmd);
		if (access(route, X_OK) == 0)
			break ;
		free(route);
		route = NULL;
		i++;
	}
	i = 0;
	if (!route)
		free_error(pipex, "Couldn't find the command in $PATH", 1);
	return (route);
}

void	process(t_pipe *pipex, char **env)
{
	pid_t	child;
	char	*cmd_route[2];
	int		fd_pipe[2];

	cmd_route[0] = search_cmd(pipex->cmd[0][0], pipex);
	cmd_route[1] = search_cmd(pipex->cmd[1][0], pipex);
	printf("CMD ROUTE 1-> %s", cmd_route[0]);
	printf("CMD ROUTE 1-> %s", cmd_route[1]);
	printf("rutas puestas\n");
	if (!cmd_route[0] || !cmd_route[1])
	{
		free_pipex(pipex);
		return ;
	}
	pipe(fd_pipe);
	printf("pipe puesto\n");
	child = fork();
	if (child == 0)
	{
		dup2(fd_pipe[1], STDOUT_FILENO);
		dup2(pipex->fd[0], STDIN_FILENO);
		fprintf(stderr, "HIJO -> %d\n",getpid()); // ELIMINAR
		execve(cmd_route[0], pipex->cmd[0], env);
		close(fd_pipe[1]);
	}
	else if (child > 0)
	{
		dup2(fd_pipe[0], STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
		fprintf(stderr, " PADRE -> %d\n",getpid()); // ELIMINAR
		execve(cmd_route[1], pipex->cmd[1], env);
		close(fd_pipe[0]);
	}
	else
		perror("perror:");
}

int	main(int ac, char **av, char **env)
{
	t_pipe	*pipex;
	char	*route;

	if (ac != 5)
		error_msg("Not enough arguments", ARGC);
	pipex = ft_calloc(1, sizeof(t_pipe));
	if (!pipex)
		error_msg("MALLOC FAIL", 3);
	parse_pipe(av, env, pipex);
	process(pipex, env);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	free_pipex(pipex);
	return (0);
}
