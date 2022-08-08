/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:43:02 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/08 20:13:06 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	init_data(t_data *data)
{
	data->cmd1_path = NULL;
	data->cmd2_path = NULL;
	data->env_path = NULL;
	data->fd[0] = open("infile", O_RDWR);
	if (data->fd[0] < 0)
		return (perror("Open failed "), 0);
	data->fd[1] = open("outfile", O_CREAT, O_RDWR);
	if (data->fd[1] < 0)
		return (perror("Open failed "), 0);
	return (1);
}

void	free_data(t_data data)
{
	if (data.cmd1_path)
		free(data.cmd1_path);
	if (data.cmd2_path)
		free(data.cmd2_path);
}
