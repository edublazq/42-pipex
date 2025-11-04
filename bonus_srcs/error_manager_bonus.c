/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:14:03 by edblazqu          #+#    #+#             */
/*   Updated: 2025/11/04 12:14:04 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	exit_error(char *msg, int exit_code)
{
	perror(msg);
	exit (exit_code);
}

void	free_exit(void *to_free, char *msg, int exit_code)
{
	free_pipex(to_free);
	exit_error(msg, exit_code);
}
