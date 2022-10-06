/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:59:33 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/06 16:38:58 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		return (msg("Tuto : ./pipex infile cmd[1] [..] cmd[x] outfile"), 1);
	data.cmd = create_list(ac);
	if (!init_data(&data, ac, av, envp))
		return (free_list(data.cmd), 1);
	if (!pipex(&data, envp))
		return (1);
	return (0);
}
