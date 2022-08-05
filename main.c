/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:32:36 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/05 16:47:31 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int ac, char **av, char **envp)
{
	// int	f1;
	// int	f2;

	// if (ac != 4)
	// {
	// 	ft_putstr_fd("There isn't 4 arguments !\n", 2);
	// 	return (1);
	// }
	// f1 = open(av[0], O_RDONLY);
	// f1 = open(av[4], O_CREAT | O_RDWR | O_TRUNC);
	// if (f1 < 0 || f2 < 0)
	// 	return (-1);
	// pipex(f1, f2, av, envp);

	// char *options[3] = {av[1],  NULL, NULL};

    (void)ac;
    // (void)av;
    // (void)envp;
	char	*env_path;
	char	*cmd_path;

	env_path = find_str_in_env(envp, "PATH");
	// printf("%s\n", env_path);
	cmd_path = find_cmd_path(av[1], env_path, envp);
	printf("%s\n", cmd_path);
    // execve("/usr/bin/wc", options, envp);
	return (0);
}

//	-Verifier si la commande existe avec access avant de lance, exec va executer
//		meme des commandes inexistantes
//	- cherche "path" (strnchr) dans envp (arg main)
//	- Split les resultats separes de ":"
//	- Verifier un a un si la commande est dans le x-eme path (precedemment split)
//	- si cmd1 n'existe pas, quand meme executer cmd2 (si elle existe)
