/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:25:46 by jeshin            #+#    #+#             */
/*   Updated: 2024/01/24 15:14:20 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_envtab(char *envp[])
{
	int		i;
	char	**tab;
	char	*tmp;

	i = -1;
	tmp = 0;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
		{
			tmp = ft_strnstr(envp[i], "PATH", 4) + 5;
			tab = ft_split(tmp, ':');
			i = -1;
			while (tab[++i])
			{
				tmp = ft_strjoin(tab[i], "/");
				free(tab[i]);
				tab[i] = tmp;
			}
			return (tab);
		}
	}
	return (0);
}

void	link_lst(t_list **lst, char *s, t_str_agr *ags)
{
	t_list	*new;

	if (!get_mid_substr(s, &(ags->tmp_s), ags->i, ags->pos))
		exit_with_errmsg("substr error");
	if (ags->have_lst_made == FALSE)
	{
		*lst = ft_lstnew(((char *)ags->tmp_s));
		ags->have_lst_made = TRUE;
	}
	else
	{
		new = ft_lstnew((char *)ags->tmp_s);
		ft_lstadd_back(lst, new);
	}
	if (s[ags->i] != 0)
	{
		while (s[ags->i] == ' ')
			(ags->i)++;
		ags->pos = ags->i;
	}
}

int	get_cmdlst(char *s, t_list **cmd_lst)
{
	t_str_agr	ags;

	init_str_agr(&ags);
	while (s[ags.i])
	{
		if (s[ags.i] == '\'' && ags.dq == FALSE)
			ags.sq = !ags.sq;
		else if (s[ags.i] == '"' && ags.sq == FALSE)
			ags.dq = !ags.dq;
		if (ags.sq == FALSE && ags.dq == FALSE && \
		(s[ags.i] == ' ' || s[ags.i] == 0))
			link_lst(cmd_lst, s, &ags);
		else
			(ags.i)++;
	}
	if (ags.sq || ags.dq)
	{
		ft_lstclear(cmd_lst, free);
		return (0);
	}	
	if (s[ags.i] == 0)
		link_lst(cmd_lst, s, &ags);
	return (1);
}

int	get_opts(char *s, char ***tab)
{
	t_list	*lst;
	t_list	*head;
	int		size_lst;
	int		i;

	if (!get_cmdlst(s, &lst))
		exit_with_errmsg("cmd error\n");
	head = lst;
	size_lst = ft_lstsize(lst);
	*tab = (char **)malloc(sizeof(char *) * (size_lst + 1));
	if (*tab == 0)
	{
		ft_lstclear(&lst, free);
		return (0);
	}
	(*tab)[size_lst] = 0;
	i = -1;
	while (++i < size_lst)
	{
		(*tab)[i] = (lst->content);
		lst = lst->next;
	}
	return (1);
}

char	*get_path(char *cmd, char *envp[])
{
	char	**envtab;
	char	*path;
	int		i;

	if (cmd == 0)
		return (0);
	envtab = get_envtab(envp);
	i = -1;
	while (envtab[++i])
	{
		path = ft_strjoin(envtab[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_tab(envtab);
			return (path);
		}
		free(path);
	}
	free_tab(envtab);
	return (0);
}
