/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:15:38 by jeshin            #+#    #+#             */
/*   Updated: 2024/01/24 18:05:10 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	care_here_doc(char *limiter, t_ags *ags)
{
	int		size_lim;
	char	*buf;
	int		tmp_fd;

	ags->is_h_doc = 1;
	tmp_fd = open("tmp_f", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp_fd < 0)
		exit_with_errmsg("open error");
	size_lim = ft_strlen(limiter);
	while (TRUE)
	{
		buf = get_next_line(0);
		if (ft_strncmp(buf, limiter, size_lim) == 0)
		{
			close(tmp_fd);
			break ;
		}
		write(tmp_fd, buf, ft_strlen(buf));
	}
	free(buf);
	ags->in_f = "tmp_f";
	return ;
}

int	make_opttab_of_ags(t_ags *ags, int ac, char **av)
{
	int	i;

	i = 0;
	ags->n_cmd = ac -3 - ags->is_h_doc;
	ags->opts_tab = (char ***)malloc(sizeof(char **) *(ags->n_cmd + 1));
	(ags->opts_tab)[ags->n_cmd] = 0;
	while (i < (ags->n_cmd))
	{
		if (get_opts(av[i + 2 + ags->is_h_doc], &((ags->opts_tab)[i])) == 0)
		{
			free(ags->opts_tab);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_ags(t_ags *ags, int ac, char **av)
{
	if (ac < 5)
		exit_with_errmsg("argc error");
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		care_here_doc(av[2], ags);
	else
	{
		ags->is_h_doc = 0;
		ags->in_f = av[1];
	}
	ags->out_f = av[ac - 1];
	if (make_opttab_of_ags(ags, ac, av) == -1)
		return (-1);
	return (0);
}
