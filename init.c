/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:15:45 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/01 20:48:04 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_ags(t_ags *ags, int ac, char **av)
{
	if (ac != 5)
		exit_with_errmsg("argc error");
	ags->in_f_fd = open(av[1], O_RDONLY);
	if (ags->in_f_fd < 0)
		exit_with_errmsg("open infile error");
	ags->out_f_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ags->out_f_fd < 0)
		exit_with_errmsg("open outfile error");
	get_opts(av[2], &(ags->opts_tab)[0]);
	get_opts(av[3], &(ags->opts_tab)[1]);
	if (pipe(ags->pipe_fd) == -1)
		exit_with_errmsg("pipe_tab error");
	ags->idx = -1;
	return (0);
}
