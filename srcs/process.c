/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:48:49 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/03 17:01:22 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

// void	child_process(int f1, int cm1)
// {
// 	dup2(f1, STDIN_FILENO);
// }
