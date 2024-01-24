/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:41:22 by jeshin            #+#    #+#             */
/*   Updated: 2024/01/24 15:21:28 by jeshin           ###   ########.fr       */
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

typedef struct s_str_agr
{
	int		dq;
	int		sq;
	int		i;
	int		pos;
	int		have_lst_made;
	char	*tmp_s;
}		t_str_agr;

void	exit_with_errmsg(char *msg);
void	free_tab(char	**tab);
void	init_str_agr(t_str_agr *chunk);
int		get_mid_substr(char *s, char **ret, int i, int pos);
char	*get_path(char *cmd, char *envp[]);
int		get_opts(char *s, char ***tab);
#endif