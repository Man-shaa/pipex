/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:23:48 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/02 18:18:05 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	init_to_null(t_data *data, int n)
{
	t_cmd	*tmp;

	data->env_path = NULL;
	data->cmd_count = 0;
	data->fd_infile = -1;
	data->fd_outfile = -1;
	while (n >= 0)
	{
		data->pid[n] = -1;
		n--;
	}
	tmp = data->cmd;
	while (tmp)
	{
		tmp->cmd_args = NULL;
		tmp->cmd_path = NULL;
		tmp = tmp->next;
	}
}

int	init_data(t_data *data, int ac, char **av, char **envp)
{
	data->cmd_nb = ac - 3;
	data->pipe_nb = 2 * (data->cmd_nb - 1);
	data->pid = ft_calloc(data->cmd_nb, sizeof(pid_t));
	if (!data->pid)
		return (msg("Malloc pid array failed"), 0);
	init_to_null(data, data->cmd_nb - 1);
	data->env_path = find_str_in_env(envp, "PATH=");
	data->fd_infile = open(av[1], O_RDONLY);
	if (data->fd_infile < 0)
		return (ft_free(data->pid), msg("Open infile failed"), 0);
	data->fd_outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_outfile < 0)
		return (ft_free(data->pid), msg("Open outfile failed"), 0);
	data->pipe = ft_calloc(sizeof(int), data->pipe_nb);
	if (!data->pipe)
		return (ft_free(data->pid), msg("Malloc pipe failed"), 0);
	if (!init_cmd(data, ac, av))
		return (ft_free(data->pid), close_pipes(data), ft_free(data->pipe), 0);
	if (!create_pipes(data))
		return (ft_free(data->pid), close_pipes(data), ft_free(data->pipe), 0);
	return (1);
}

int	init_cmd(t_data *data, int ac, char **av)
{
	int		i;
	t_cmd	*tmp;

	i = 2;
	tmp = data->cmd;
	while (i < ac - 1)
	{
		data->cmd->cmd_args = ft_split(av[i], ' ');
		if (!data->cmd->cmd_args[0])
		{
			data->cmd = tmp;
			return (msg("Command not found"), 0);
		}
		data->cmd->cmd_path = find_cmd_path(data, data->cmd->cmd_args[0],
				data->env_path);
		if (!data->cmd->cmd_path && i == ac - 2)
		{
			data->cmd = tmp;
			return (0);
		}
		data->cmd = data->cmd->next;
		i++;
	}
	data->cmd = tmp;
	return (1);
}
