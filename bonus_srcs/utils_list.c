/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:27:02 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/06 16:35:43 by msharifi         ###   ########.fr       */
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
	if (ac > 3)
		cmd = ft_lstnew();
	while (i < ac - 3)
	{
		add_last(cmd);
		i++;
	}
	return (cmd);
}
