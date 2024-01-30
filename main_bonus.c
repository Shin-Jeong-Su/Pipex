/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:29:52 by jeshin            #+#    #+#             */
/*   Updated: 2024/01/30 18:42:39 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_ags	ags;
	int		status;
	int		i;

	init_ags(&ags, argc, argv);
	while (++(ags.idx) < ags.n_cmd)
		go_child(ags, envp);
	close_all_pipe(&ags);
	i = -1;
	while (++i < ags.n_cmd)
		waitpid(-1, &status, 0);
	close(ags.in_f_fd);
	close(ags.out_f_fd);
	free_all(&ags);
	return (0);
}
