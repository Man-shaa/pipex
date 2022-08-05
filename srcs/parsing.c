/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:16:33 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/05 16:46:49 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// // parsing (somewhere in your code)
// char *PATH_from_envp;
// char **mypaths;
// char **mycmdargs;
// // retrieve the line PATH from envp
// PATH_from_envp = ft_substr(envp ....);
// mypaths = ft_split(PATH_from_envp, ":"); // see section 4 for a
//                                             // small note[0]
// mycmdargs = ft_split(ag[2], " ");
// // in your child or parent process
// int  i;
// char *cmd;
// i = 0;
// while (mypaths[i])
// {
//     cmd = ft_join(mypaths[i], ag[2]); // protect your ft_join
//     execve(cmd, mycmdargs, envp); // if execve succeeds, it exits
//     // perror("Error"); <- add perror to debug
//     free(cmd) // if execve fails, we free and we try a new path
// 	i++;
// }
// return (EXIT_FAILURE);

char	*find_str_in_env(char **envp, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		while (envp[i][j] == str[j])
			j++;
		if (str[j] == '\0')
			return (envp[i]);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd, char *env_path, char **envp)
{
	int		i;
	char	**all_paths;
	char	*path;
	(void)envp;

	i = 0;
	all_paths = ft_split(env_path, ':');
	while (all_paths[i])
	{
		path = ft_strjoin(all_paths[i], cmd);
		if (printf("Return exec : %d	", execve(path, &cmd, envp)))
		{
			printf("PAS BON : %s\n\n", path);
			free(path);
		}
		else
			printf("BON : %s\n", path);
		// access(path, W_OK);
		// perror("Error");
		i++;
	}
	free_tab(all_paths);
	return (NULL);
}
