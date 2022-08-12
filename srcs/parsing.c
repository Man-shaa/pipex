/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:16:33 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/12 18:20:15 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	is_path(char *av)
{
	if (!av)
		return (1);
	if (access(av, F_OK | X_OK) == 0)
		return (0);
	return (1);
}

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
			return (&envp[i][j]);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd, char *env_path)
{
	int		i;
	char	**all_paths;
	char	*path;

	i = 0;
	all_paths = ft_split(env_path, ':');
	if (!all_paths && is_path(cmd))
		return (perror("Access for this command not found"), NULL);
	if (!is_path(cmd))
		return (free_tab(all_paths), cmd);
	while (all_paths[i])
	{
		path = ft_strjoin(all_paths[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (free_tab(all_paths), path);
		free(path);
		i++;
	}
	free_tab(all_paths);
	return (perror("Access for this command not found"), NULL);
}
