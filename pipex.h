/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:31:05 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/02 17:10:29 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// print.c
size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);

// process.c
void    pipex(int f1, int f2, char *cmd1, char *cmd2);
void	child_process(int f1, int cm1);

#endif