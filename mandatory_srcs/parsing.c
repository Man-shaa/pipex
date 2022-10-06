/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:16:33 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/06 16:40:03 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	is_path(t_data *data, char *av, int c)
{
	if (!av)
		return (1);
	if (!ft_strchr(av, '/'))
		return (1);
	if (access(av, F_OK | X_OK) == 0)
	{
		if (c == 1)
			data->cmd1_path = av;
		else if (c == 2)
			data->cmd2_path = av;
		return (0);
	}
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

char	*find_cmd_path(t_data *data, char *cmd, char *env_path)
{
	int		i;
	char	**all_paths;
	char	*path;

	i = 0;
	all_paths = ft_split(env_path, ':');
	if (!all_paths && is_path(data, cmd, 0))
		return (msg("env not found, please specify a path directly"), NULL);
	if (!is_path(data, cmd, 0))
		return (free_tab(all_paths), cmd);
	while (all_paths[i])
	{
		path = ft_strjoin(all_paths[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (free_tab(all_paths), path);
		ft_free(path);
		i++;
	}
	free_tab(all_paths);
	return (msg("No such file or directory"), NULL);
}
