/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:48:49 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/12 17:36:49 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int	child_one(t_data *data, char **av, char **envp)
{
	close(data->fd[0]);
	if (dup2(data->fd[1], STDOUT_FILENO) < 0)
		return (perror("dup2 fd[1] failed "), 0);
	data->cmd1_args = ft_split(av[2], ' ');
	if (!data->cmd1_args)
		return (perror("There isn't an cmd1"), 0);
	if (is_path(data->cmd1_args[0]))
		data->cmd1_path = find_cmd_path(data->cmd1_args[0], data->env_path);
	if (data->cmd1_path == NULL)
		return (free_tab(data->cmd1_args), 0);
	if (execve(data->cmd1_path, data->cmd1_args, envp) == -1)
		return (perror("Execute cmd 1 failed "), 0);
	return (1);

}

int	child_two(t_data *data, char **av, char **envp)
{
	close(data->fd[1]);
	if (dup2(data->fd[0], STDIN_FILENO) < 0)
		return (perror("dup2 fd[0] failed "), 0);
	data->cmd2_args = ft_split(av[3], ' ');
	if (!data->cmd2_args)
		return (perror("There isn't an cmd2"), 0);
	if (is_path(data->cmd2_args[0]))
		data->cmd2_path = find_cmd_path(data->cmd2_args[0], data->env_path);
	if (data->cmd2_path == NULL)
		return (free_tab(data->cmd2_args), 0);
	if (execve(data->cmd2_path, data->cmd2_args, envp) == -1)
		return (perror("Execute cmd 2 failed "), 0);
	return (1);
}

int	pipex(t_data data, char **av, char **envp)
{
	data.pid1 = fork();
	if (data.pid1 < 0)
		return (perror("Fork 1 failed "), 0);
	if (data.pid1 == 0)
		child_one(&data, av, envp);
	data.pid2 = fork();
	if (data.pid2 < 0)
		return (perror("Fork 2 failed "), 0);
	if (data.pid2 == 0)
		child_two(&data, av, envp);
	close(data.fd[0]);
	close(data.fd[1]);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	return (1);
}
