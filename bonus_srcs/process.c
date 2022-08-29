/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:56:23 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/29 15:06:29 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	child_process(t_data *data)
{

}

int	create_fork(t_data *data)
{
	int	pid;

	pid = fork;
	if (pid < 0)
		return (perror("Fork failed "), 0);
	if (pid == 0)
		child_process;
}

int	pipex(t_data *data)
{
	create_fork;
}

// rajouter pipe(data->fd)