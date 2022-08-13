/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:15:21 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/13 19:52:35 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char			*cmd_path;
	char			**cmd_args;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_data
{
	int		fd[2];
	pid_t	pid;
	int		fd_infile;
	int		fd_outfile;
	char	*env_path;
	t_cmd	*cmd;
}				t_data;

// utils_list.c
int		init_data(t_data *data, int ac, char **av);
t_cmd	*ft_lstnew(void);
void	add_last(t_cmd *cmd);
t_cmd	*create_list(int ac);

// utils.c
void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlen(char *str);
int		ft_strchr(char *str, int c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);


#endif