/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:43:02 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/10 22:30:09 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	init_data(t_data *data, char **envp)
{
	data->cmd1_path = NULL;
	data->cmd2_path = NULL;
	data->env_path = NULL;
	data->fd_infile = open("infile", O_RDWR);
	if (data->fd_infile < 0)
		return (perror("Open infile failed "), 0);
	data->fd_outfile = open("outfile", O_CREAT | O_TRUNC | O_RDWR,
			S_IWUSR | S_IRUSR);
	if (data->fd_outfile < 0)
		return (perror("Open outfile failed "), 0);
	data->env_path = find_str_in_env(envp, "PATH");
	if (dup2(data->fd_infile, STDIN_FILENO) < 0)
		return (perror("dup2 infile failed "), 0);
	if (dup2(data->fd_outfile, STDOUT_FILENO) < 0)
		return (perror("dup2 outfile failed "), 0);
	close(data->fd_infile);
	close(data->fd_outfile);
	return (1);
}

void	free_data(t_data data)
{
	if (data.cmd1_path)
		free(data.cmd1_path);
	if (data.cmd2_path)
		free(data.cmd2_path);
}
