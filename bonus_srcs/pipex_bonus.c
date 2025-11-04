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

static void	set_path(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->path[i] != NULL)
	{
		pipex->path[i] = ft_strjoin(pipex->path[i], "/");
		printf("%s\n", pipex->path[i]);
		i++;
	}
}

static void	init_pipex(int ac, char **av, char **env, t_pipex *pipex)
{
	size_t	i;

	set_number(ac, av, pipex);
	set_fd();
	i = 0;
	while (i < pipex->nb)
		pipex->cmd[i] = ft_split(av[i++ + 2], ' ');
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
	if (!(env[i]) || !pipex->path)
		free_exit(pipex, "Couldn't find $PATH", 3);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (ac < 5)
		exit_error("Not enough arguments", 1);
	
	
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		error_exit("malloc fail: ", 1);
	init_pipex(ac, av, env, pipex);
}
