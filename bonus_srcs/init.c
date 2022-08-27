/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:23:48 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/27 18:16:53 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	init_to_null(t_data *data)
{
	t_cmd	*tmp;

	data->env_path = NULL;
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
	init_to_null(data);
	data->env_path = find_str_in_env(envp, "PATH=");
	data->fd_infile = open("infile", O_RDONLY);
	if (data->fd_infile < 0)
		return (perror("Open infile failed "), 0);
	data->fd_outfile = open("outfile", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_outfile < 0)
		return (perror("Open outfile failed "), 0);
	// if (dup2(data->fd_infile, STDIN_FILENO) < 0)
	// 	return (perror("dup2 infile failed "), 0);
	// if (dup2(data->fd_outfile, STDOUT_FILENO) < 0)
	// 	return (perror("dup2 outfile failed "), 0);
	close(data->fd_infile);
	close(data->fd_outfile);
	if (!init_cmd(data, ac, av))
		return (0);
	return (1);
}

int	init_cmd(t_data *data, int ac, char **av)
{
	int		i;
	t_cmd	*tmp;

	i = 1;
	tmp = data->cmd;
	while (i < ac)
	{
		tmp->cmd_args = ft_split(av[i], ' ');
		if (!tmp->cmd_args[0])
			return (perror("Command not found "), 0);
		tmp->cmd_path = find_cmd_path(data, tmp->cmd_args[0],
				data->env_path);
		if (!tmp->cmd_path)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
