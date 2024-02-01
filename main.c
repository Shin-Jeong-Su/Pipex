/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:49:48 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/01 21:09:28 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		status;
	t_ags	ags;

	init_ags(&ags, argc, argv);
	while (++ags.idx < 2)
	{
		ags.child_pid[ags.idx] = fork();
		if (ags.child_pid[ags.idx] == -1)
			exit_with_errmsg("fork error");
		if (ags.child_pid[ags.idx] == 0)
			go_child(&ags, envp);
	}
	close(ags.pipe_fd[0]);
	close(ags.pipe_fd[1]);
	ags.idx = -1;
	while (++ags.idx < 2)
		waitpid(ags.child_pid[ags.idx], &status, 0);
	close(ags.in_f_fd);
	close(ags.out_f_fd);
	free_tab(ags.opts_tab[0]);
	free_tab(ags.opts_tab[1]);
	return (0);
}
