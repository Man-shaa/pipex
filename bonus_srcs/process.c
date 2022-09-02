/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:56:23 by msharifi          #+#    #+#             */
/*   Updated: 2022/09/02 17:45:24 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	create_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_nb - 1)
	{
		if (pipe(data->pipe + 2 * i) < 0)
			return (perror("Pipe failed "), 0);
		i++;
	}
	return (1);
}

void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->pipe_nb))
	{
		close(data->pipe[i]);
		i++;
	}
}

void	double_dup2(int fd1, int fd2)
{
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
}

int	child(t_data *data, t_cmd *cmd, char **envp)
{
	data->pid = fork();
	if (data->pid < 0)
		return (perror("Fork failed "), 0);
	if (data->pid == 0)
	{
		if (data->cmd_count == 0)
			double_dup2(data->fd_infile, data->pipe[1]);
		else if (data->cmd_count == data->cmd_nb - 1)
			double_dup2(data->pipe[2 * data->cmd_count - 2], data->fd_outfile);
		else
			double_dup2(data->pipe[2 * data->cmd_count - 2], data->pipe[2 * data->cmd_count + 1]);
		close_pipes(data);
		if (!cmd->cmd_path)
			return (free(data->pipe), perror("No cmd path "), 0);
		if (execve(cmd->cmd_path, cmd->cmd_args, envp) == -1)
			return (perror("Execute failed ! "), 0);
	}
	return (1);
}

int	pipex(t_data *data, char **envp)
{
	t_cmd	*tmp;

	tmp = data->cmd;
	while (tmp)
	{
		if (!child(data, tmp, envp))
			return (free_list(data->cmd), 0);
		tmp = tmp->next;
		data->cmd_count++;
	}
	close_pipes(data);
	waitpid(-1, NULL, 0);
	free_list(data->cmd);
	free(data->pipe);
	return (1);
}
