/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:31:05 by msharifi          #+#    #+#             */
/*   Updated: 2022/08/10 22:29:33 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		fd_infile;
	int		fd_outfile;
	char	*env_path;
	char	*cmd1_path;
	char	**cmd1_args;
	char	*cmd2_path;
	char	**cmd2_args;
}				t_data;

// init.c
int		init_data(t_data *data, char **envp);
void	free_data(t_data data);

// parsing.c
int		is_path(char *av);
char	*find_str_in_env(char **envp, char *str);
char	*find_cmd_path(char *cmd, char *env_path);

// process.c
int		child_one(t_data *data, char **av, char **envp);
int		child_two(t_data *data, char **av, char **envp);
int		pipex(t_data data, char **av, char **envp);

// split.c
void	free_tab(char **tab);
int		word_count(char *str, char set);
int		char_count(char *str, char set, int pos);
char	*ft_putword(char *str, char *tab, char set, int pos);
char	**ft_split(char	*str, char set);

// utils.c
void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlen(char *str);
int		ft_strchr(char *str, int c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif