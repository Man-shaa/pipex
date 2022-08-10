/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:32:36 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/10 22:31:55 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void) ac;
	if (pipe(data.fd) == -1)
		return (1);
	if (!init_data(&data, envp))
		return (free_data(data), 1);
	if (!pipex(data, av, envp))
		return (1);
	free_data(data);
	return (0);
}
