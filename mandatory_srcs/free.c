/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:36:58 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/02 16:50:14 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free(void *addr)
{
	free(addr);
	addr = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
}

void	free_data(t_data data)
{
	if (data.cmd1_path)
		ft_free(data.cmd1_path);
	if (data.cmd2_path)
		ft_free(data.cmd2_path);
	if (data.cmd1_args)
		free_tab(data.cmd1_args);
	if (data.cmd2_args)
		free_tab(data.cmd2_args);
}

void	close_all(t_data *data)
{
	if (data->fd_infile != -1)
		close(data->fd_infile);
	if (data->fd_outfile != -1)
		close(data->fd_outfile);
	if (data->fd[0] != -1)
		close (data->fd[0]);
	if (data->fd[1] != -1)
		close (data->fd[1]);
}