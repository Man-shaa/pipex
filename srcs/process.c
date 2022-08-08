/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:48:49 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/08 20:09:07 by msharifi         ###   ########.fr       */
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
	printf("fd[0] : %d\nfd[1] : %d\nSTDOUT : %d\n", data->fd[0], data->fd[1], STDOUT_FILENO);
	if (dup2(data->fd[1], STDOUT_FILENO) < 0)
		return (perror("dup2 failed "), 1);
	printf("fd[0] : %d\nfd[1] : %d\nSTDOUT : %d\n", data->fd[0], data->fd[1], STDOUT_FILENO);
	close(data->fd[0]);
	close(data->fd[1]);
	if (is_path(data, options[0]))
		data->cmd1_path = find_cmd_path(&options[0], data->env_path);
	if (!data->cmd1_path)
		return (0);
	if (execve(data->cmd1_path, options, envp) == -1)
		return (perror("Execute failed "), 1);
	return (1);
}
