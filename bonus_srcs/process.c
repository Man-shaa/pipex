/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:56:23 by msharifi          #+#    #+#             */
/*   Updated: 2022/09/02 16:23:44 by msharifi         ###   ########.fr       */
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
			return (perror(" pipe failed "), 0);
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

int	redirect(t_cmd *cmd, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		return (perror("pipe failed "), 0);
	pid = fork();
	if (pid < 0)
		return (perror("Fork failed "), 0);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			return (perror("Dup2 child failed "), 0);
		if (!cmd->cmd_path)
			return (0);
		if (execve(cmd->cmd_path, cmd->cmd_args, envp) == -1)
			return (perror("Execute failed ! "), 0);
	}
	else
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			return (perror("Dup2 parent failed "), 0);
		waitpid(pid, NULL, 0);
	}
	return (1);
}

int	pipex(t_data *data, char **envp)
{
	t_cmd	*tmp;

	tmp = data->cmd;
	redirect(tmp, envp);
	tmp = tmp->next;
	while (tmp->next)
	{
		if (!redirect(tmp, envp))
			return (free_list(data->cmd), 0);
		tmp = tmp->next;
	}
	if (execve(tmp->cmd_path, tmp->cmd_args, envp) == -1)
		return (perror("Execute failed ! "), 0);
	return (1);
}
