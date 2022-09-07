/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:59:33 by msharifi          #+#    #+#             */
/*   Updated: 2022/09/07 19:30:44 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

void	print_data(t_data *data)
{
	int		i;
	int		j;
	t_cmd	*tmp;

	i = 1;
	tmp = data->cmd;
	printf("\n");
	printf("env_path : %s\n\n", data->env_path);
	while (tmp)
	{
		j = 0;
		printf("************CMD[%i]************\n\n", i);
		printf("cmd_path : %s\n", tmp->cmd_path);
		while (tmp->cmd_args[j])
		{
			printf("cmd_args[%d] : %s\n", j, tmp->cmd_args[j]);
			j++;
		}
		printf("\n");
		i++;
		tmp = tmp->next;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		return (perror("Tuto : ./pipex infile cmd[1] [..] cmd[x] outfile"), 1);
	data.cmd = create_list(ac);
	if (!init_data(&data, ac, av, envp))
		return (free_list(data.cmd), 1);
	if (!pipex(&data, envp))
		return (1);
	return (0);
}
