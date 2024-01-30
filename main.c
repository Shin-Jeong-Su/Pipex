/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:49:48 by jeshin            #+#    #+#             */
/*   Updated: 2024/01/29 19:53:08 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
		exit_with_errmsg("argc error");
	if (pipe(p_fd) == -1)
		exit_with_errmsg("pipe error");
	pid = fork();
	if (pid == -1)
		exit_with_errmsg("fork error");
	if (pid == 0)
		go_child(argv, p_fd, envp);
	else
		go_parent(argv, p_fd, envp);
}
