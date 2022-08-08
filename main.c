/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:32:36 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/08 20:11:40 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int ac, char **av, char **envp)
{
    (void)ac;
	t_data	data;
	int		status;
	char	*options[3] = {av[1], NULL, NULL};
	
	if (!init_data(&data))
		return (1);
	if (pipe(data.fd) == -1)
		return (1);
	data.env_path = find_str_in_env(envp, "PATH");
	data.pid1 = fork();
	if (data.pid1 < 0)
		return (perror("Fork failed "), 1);
	if (data.pid1 == 0)
	{
		if (!child_one(&data, options, envp))
		{
			perror("Error ");
			return (1);
		}
	}
	else
	{
		printf("Hi from main process\n");
		close(data.fd[0]);
		close(data.fd[1]);
		waitpid(data.pid1, &status, 0);
	}
	waitpid(data.pid1, &status, 0);
	free_data(data);
	return (0);
}

//	- Verifier si on nous envoie la commande (chercher le path) ou directement le path
