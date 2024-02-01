/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:39 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/01 20:43:33 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	my_dup2(int rd, int wr)
{
	if (dup2(rd, 0) < 0)
		perror("dup2 error");
	if (dup2(wr, 1) < 0)
		perror("dup2 error");
}

void	go_child(t_ags *ags, char *envp[])
{
	char	**opts;

	if (ags->idx == 0)
		my_dup2(ags->in_f_fd, ags->pipe_fd[1]);
	else if (ags->idx == 1)
		my_dup2(ags->pipe_fd[0], ags->out_f_fd);
	close(ags->pipe_fd[0]);
	close(ags->pipe_fd[1]);
	opts = ags->opts_tab[ags->idx];
	execve(get_path(opts[0], envp), opts, envp);
	perror("execve error");
}
