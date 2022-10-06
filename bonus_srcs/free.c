/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:34:31 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/06 17:09:52 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_free(void *addr)
{
	free(addr);
	addr = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
}

void	free_list(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (cmd)
	{
		if (tmp->cmd_path)
			ft_free(tmp->cmd_path);
		if (tmp->cmd_args)
			free_tab(tmp->cmd_args);
		cmd = cmd->next;
		ft_free(tmp);
		tmp = cmd;
	}
}
