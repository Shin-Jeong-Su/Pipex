/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:24:25 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/01 17:15:38 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_errmsg(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	init_str_agr(t_str_ags *chunk)
{
	chunk->dq = 0;
	chunk->sq = 0;
	chunk->i = 0;
	chunk->pos = 0;
	chunk->have_lst_made = 0;
	chunk->tmp_s = 0;
}

int	get_mid_substr(char *s, char **ret, int i, int pos)
{
	if (i > 0 && s[i - 1] == '\'' && s[pos] == '\'')
		*ret = ft_substr(s, pos + 1, i - 2 - pos);
	else if (i > 0 && s[i - 1] == '"' && s[pos] == '"')
		*ret = ft_substr(s, pos + 1, i - 2 - pos);
	else
		*ret = ft_substr(s, pos, i - pos);
	if (*ret)
		return (0);
	return (-1);
}
