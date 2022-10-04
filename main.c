/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:32:36 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/04 16:31:06 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 5)
		return (msg("Tuto : ./pipex infile cmd1 cmd2 outfile"), 1);
	if (pipe(data.fd) == -1)
		return (2);
	if (!init_data(&data, ac, av, envp))
		return (free_data(data), 3);
	if (!pipex(data, av, envp))
		return (4);
	free_data(data);
	return (0);
}
