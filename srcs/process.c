/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:48:49 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/09 15:35:51 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// void    pipex(int f1, int f2, char *cmd1, char *cmd2)
// {
//     int   end[2];
//     int   status;
//     pid_t child1;
//     pid_t child2;
//     pipe(end);
//     child1 = fork();
//     if (child1 < 0)
//          return (perror("Fork: "));
//     if (child1 == 0)
//         child_one(f1, cmd1);
//     child2 = fork();
//     if (child2 < 0)
//          return (perror("Fork: "));
//     if (child2 == 0)
//         child_two(f2, cmd2);
//     close(end[0]);
//     close(end[1]);
//     waitpid(child1, &status, 0);
//     waitpid(child2, &status, 0);
// }

int	child_one(t_data *data, char **options, char **envp)
{
	if (dup2(data->fd_infile, STDIN_FILENO) < 0)
		return (perror("dup2 infile failed "), 0);
	if (dup2(data->fd[1], STDOUT_FILENO) < 0)
		return (perror("dup2 fd[1] failed "), 0);
	close(data->fd[0]);
	close(data->fd[1]);
	if (execve(data->cmd1_path, &options[0], envp) == -1)
		return (perror("Execute cmd 1 failed "), 0);
	return (1);
}

int	child_two(t_data *data, char **options, char **envp)
{
	if (dup2(data->fd[0], STDIN_FILENO) < 0)
		return (perror("dup2 fd[0] failed "), 0);
	if (dup2(data->fd_outfile, STDOUT_FILENO) < 0)
		return (perror("dup2 outfile failed "), 0);
	close(data->fd[0]);
	close(data->fd[1]);
	if (execve(data->cmd2_path, &options[0], envp) == -1)
		return (perror("Execute cmd 2 failed "), 0);
	return (1);
}
