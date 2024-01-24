/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:21:15 by jeshin            #+#    #+#             */
/*   Updated: 2024/01/24 18:12:20 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define TRUE		1
# define FALSE		0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <sys/wait.h>

typedef struct s_str_agr
{
	int		dq;
	int		sq;
	int		i;
	int		pos;
	int		have_lst_made;
	char	*tmp_s;
}		t_str_agr;

typedef struct s_ags
{
	char	*in_f;
	char	*out_f;
	int		n_cmd;
	char	***opts_tab;
	int		is_h_doc;
}		t_ags;

void	exit_with_errmsg(char *msg);
void	free_tab(char	**tab);
void	init_str_agr(t_str_agr *chunk);
int		get_mid_substr(char *s, char **ret, int i, int pos);
char	*get_path(char *cmd, char *envp[]);
int		get_opts(char *s, char ***tab);
#endif