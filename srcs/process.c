/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:48:49 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/10 22:08:37 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	child_one(t_data *data, char **options, char **envp)
{
	if (dup2(data->fd[1], STDOUT_FILENO) < 0)
		return (perror("dup2 fd[1] failed "), 0);
	close(data->fd[1]);
	if (execve(data->cmd1_path, &options[0], envp) == -1)
		return (perror("Execute cmd 1 failed "), 0);
	return (1);
}

int	child_two(t_data *data, char **options, char **envp)
{
	if (dup2(data->fd[0], STDIN_FILENO) < 0)
		return (perror("dup2 fd[0] failed "), 0);
	close(data->fd[0]);
	if (execve(data->cmd2_path, &options[0], envp) == -1)
		return (perror("Execute cmd 2 failed "), 0);
	return (1);
}
