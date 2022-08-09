/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:32:36 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/09 19:44:55 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int ac, char **av, char **envp)
{
    (void)ac;
	t_data	data;
	int		status;
	char	*options[2][3] = {{av[1], NULL, NULL}, {av[2], NULL, NULL}};
	
	if (pipe(data.fd) == -1)
		return (1);
	if (!init_data(&data, options, envp))
		return (free_data(data), 1);
	data.pid1 = fork();
	if (data.pid1 < 0)
		return (perror("Fork 1 failed "), 1);
	if (data.pid1 == 0)
	{
		write(1, "child1\n", 7);
		if (!child_one(&data, options[0], envp))
		{
			perror("Error ");
			return (1);
		}
	}
	data.pid2 = fork();
	if (data.pid2 < 0)
		return (perror("Fork 2 failed "), 1);
	if (data.pid2 == 0)
	{
		write(1, "child2\n", 7);
		if (!child_two(&data, options[1], envp))
		{
			perror("Error ");
			return (1);
		}
	}
	else
	{
		write(1, "parent\n", 7);
		waitpid(data.pid1, &status, 0);
		waitpid(data.pid2, &status, 0);
		close(data.fd[0]);
		close(data.fd[1]);
	}
	free_data(data);
	return (0);
}
