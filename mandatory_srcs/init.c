/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:43:02 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/02 16:53:17 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	init_data(t_data *data, int ac, char **av, char **envp)
{
	data->cmd1_path = NULL;
	data->cmd2_path = NULL;
	data->env_path = NULL;
	data->cmd1_args = NULL;
	data->cmd2_args = NULL;
	data->fd_outfile = -1;
	data->fd_infile = open(av[1], O_RDONLY);
	if (data->fd_infile < 0)
		return (msg("Open infile failed"), 0);
	data->fd_outfile = open(av[ac - 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (data->fd_outfile < 0)
		return (msg("Open outfile failed"), 0);
	data->env_path = find_str_in_env(envp, "PATH=");
	if (dup2(data->fd_infile, STDIN_FILENO) < 0)
		return (msg("invalid infile fd"), 0);
	if (dup2(data->fd_outfile, STDOUT_FILENO) < 0)
		return (msg("invalid oufile fd"), 0);
	close(data->fd_infile);
	close(data->fd_outfile);
	return (1);
}
