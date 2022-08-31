/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:56:23 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/31 18:37:36 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	redirect(t_cmd *cmd, char **envp, int fdin)
{
	pid_t	pid;
	int		pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid < 0)
		return (perror("Fork failed "), 0);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			return (perror("Dup2 child failed "), 0);
		if (fdin == 1)
			exit(1);
		else
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
	redirect(tmp, envp, data->fd_infile);
	tmp = tmp->next;
	while (tmp->next)
	{
		if (!redirect(tmp, envp, 1))
			return (free_list(data->cmd), 0);
		tmp = tmp->next;
	}
	if (execve(tmp->cmd_path, tmp->cmd_args, envp) == -1)
		return (perror("Execute failed ! "), 0);
	return (1);
}
