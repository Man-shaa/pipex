/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:36:58 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/06 16:41:13 by msharifi         ###   ########.fr       */
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
