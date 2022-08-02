/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:16:33 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/02 17:19:04 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// parsing (somewhere in your code)
char *PATH_from_envp;
char **mypaths;
char **mycmdargs;
// retrieve the line PATH from envp
PATH_from_envp = ft_substr(envp ....);
mypaths = ft_split(PATH_from_envp, ":"); // see section 4 for a
                                            // small note[0]
mycmdargs = ft_split(ag[2], " ");
// in your child or parent process
int  i;
char *cmd;
i = 0;
while (mypaths[i])
{
    cmd = ft_join(mypaths[i], ag[2]); // protect your ft_join
    execve(cmd, mycmdargs, envp); // if execve succeeds, it exits
    // perror("Error"); <- add perror to debug
    free(cmd) // if execve fails, we free and we try a new path
	i++;
}
return (EXIT_FAILURE);
