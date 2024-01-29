/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:21:15 by jeshin            #+#    #+#             */
/*   Updated: 2024/01/29 18:02:06 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define TRUE		1
# define FALSE		0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <sys/wait.h>

typedef struct s_str_ags
{
	int		dq;
	int		sq;
	int		i;
	int		pos;
	int		have_lst_made;
	char	*tmp_s;
}		t_str_ags;

typedef struct s_ags
{
	int		in_f_fd;
	int		out_f_fd;
	int		**pipe_fd_tab;
	int		n_cmd;
	int		idx;
	char	***opts_tab;
	int		is_here_doc;
}		t_ags;

void	exit_with_errmsg(char *msg);
void	free_tab(char	**tab);
void	free_all(t_ags	*ags);
void	init_str_agr(t_str_ags *chunk);
int		get_mid_substr(char *s, char **ret, int i, int pos);
int		init_ags(t_ags *ags, int ac, char **av);
char	*get_path(char *cmd, char *envp[]);
int		get_opts(char *s, char ***tab);
void	go_child(t_ags ags, char **envp);
void	my_pipe_close(t_ags *ags, int read_p1, int write_p2);
#endif