/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:27:02 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/27 18:32:29 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

t_cmd	*ft_lstnew(void)
{
	t_cmd	*new;

	new = ft_calloc(1, sizeof(t_cmd));
	if (!new)
		return (0);
	new->cmd_args = NULL;
	new->cmd_path = NULL;
	new->next = NULL;
	return (new);
}

void	add_last(t_cmd *cmd)
{
	t_cmd	*last;
	t_cmd	*tmp;

	tmp = cmd;
	last = ft_lstnew();
	if (!cmd)
	{
		cmd = last;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	last->next = NULL;
}

t_cmd	*create_list(int ac)
{
	t_cmd	*cmd;
	int		i;

	i = 1;
	cmd = NULL;
	if (ac != 1)
		cmd = ft_lstnew();
	while (i < ac - 1)
	{
		add_last(cmd);
		i++;
	}
	return (cmd);
}

void	free_list(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (cmd)
	{
		if (tmp->cmd_args)
			free_tab(tmp->cmd_args);
		if (tmp->cmd_path)
			free(tmp->cmd_path);
		cmd = cmd->next;
		free(tmp);
		tmp = cmd;
	}
}
