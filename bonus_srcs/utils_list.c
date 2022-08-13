/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:27:02 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/13 19:52:20 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	init_data(t_data *data, int ac, char **av)
{
	data->env_path = NULL;
	data->fd_infile = open(av[1], O_RDONLY);
	if (data->fd_infile < 0)
		return (perror("Open infile failed "), 0);
	data->fd_outfile = open(av [ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_outfile < 0)
		return (perror("Open outfile failed "), 0);
	if (dup2(data->fd_infile, STDIN_FILENO) < 0)
		return (perror("dup2 infile failed "), 0);
	if (dup2(data->fd_outfile, STDOUT_FILENO) < 0)
		return (perror("dup2 outfile failed "), 0);
	close(data->fd_infile);
	close(data->fd_outfile);
	return (1);
}

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
	cmd = ft_lstnew();
	while (i < ac - 1)
	{
		add_last(cmd);
		i++;
	}
	return (cmd);
}
