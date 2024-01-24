/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:39 by jeshin            #+#    #+#             */
/*   Updated: 2024/01/24 15:12:28 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	my_execve(char **av, int nth, char *envp[])
{
	char	*path;
	char	**opts;

	if (get_opts(av[nth], &opts) == 0)
		exit_with_errmsg("opts error");
	path = get_path(opts[0],envp);
	if (path == 0)
		exit_with_errmsg("path error");
	execve(path, opts, envp);
}

void	go_child(char **av, int *p_fd, char *envp[])
{
	int		fd1;

	fd1 = open(av[1], O_RDONLY);
	if (fd1 < 0)
		exit_with_errmsg("open error");
	if (dup2(fd1, 0) < 0)
	{
		perror("dup2 of child error");
		exit(EXIT_FAILURE);
	}
	if (dup2(p_fd[1], 1) < 0)
	{
		perror("dup2 of child error");
		exit(EXIT_FAILURE);
	}
	close(p_fd[0]);
	my_execve(av, 2, envp);
}

void	go_parent(char **av, int *p_fd, char *envp[])
{
	int		fd2;

	fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 < 0)
	{
		perror("writing fd error");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd2, 1) < 0)
	{
		perror("dup2 error");
		exit(EXIT_FAILURE);
	}
	if (dup2(p_fd[0], 0) < 0)
	{
		perror("dup2 error");
		exit(EXIT_FAILURE);
	}
	close(p_fd[1]);
	my_execve(av, 3, envp);
}

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
