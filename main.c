/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:32:36 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/12 18:25:06 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 5)
		return (perror("Tuto : ./pipex infile cmd1 cmd2 outfile"), 1);
	if (pipe(data.fd) == -1)
		return (1);
	if (!init_data(&data, ac, av, envp))
		return (free_data(data), 1);
	// printf("%s\n", find_cmd_path(av[2], find_str_in_env(envp, "PATH=")));
	// printf("%s\n", find_cmd_path(av[3], find_str_in_env(envp, "PATH=")));
	if (!pipex(data, av, envp))
		return (1);
	free_data(data);
	return (0);
}
