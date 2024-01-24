/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:54:39 by jeshin            #+#    #+#             */
/*   Updated: 2024/01/24 18:08:36 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_bkup(char **bkup)
{
	if (!bkup)
		return (0);
	free(*bkup);
	*bkup = 0;
	return (0);
}

char	*_get_line(char **bkup)
{
	char		*ret;
	char		*tmp;
	size_t		i;
	size_t		bkup_size;

	bkup_size = ft_strlen(*bkup);
	if (ft_strchr(*bkup, '\n'))
	{
		i = 0;
		while ((*bkup)[i] && (*bkup)[i] != '\n')
			i++;
		ret = ft_substr(*bkup, 0, (i + 1));
		if (!ret)
			return ((char *)free_bkup(bkup));
		if (bkup_size == i + 1)
			tmp = 0;
		else
			tmp = ft_substr(*bkup, i + 1, bkup_size - (i + 1));
		free(*bkup);
		*bkup = tmp;
		return (ret);
	}
	if (!**bkup)
		return ((char *)free_bkup(bkup));
	ret = ft_substr(*bkup, 0, ft_strlen(*bkup));
	free_bkup(bkup);
	return (ret);
}

int	new_bkup(char **bkup, char *buf)
{
	char		*ret;

	ret = ft_strjoin(*bkup, buf);
	if (ret == 0)
	{
		free_bkup(bkup);
		return (0);
	}
	free(*bkup);
	*bkup = ret;
	return (1);
}

char	*get_next_line(int fd)
{
	int			rd_val;
	char		buf[BUFFER_SIZE + 1];
	static char	*bkup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (1)
	{
		rd_val = read(fd, buf, BUFFER_SIZE);
		if (rd_val < 0)
			return ((char *)free_bkup(&bkup));
		buf[rd_val] = 0;
		if (new_bkup(&bkup, buf) == 0)
			return (0);
		if (ft_strchr(bkup, '\n') || rd_val < BUFFER_SIZE)
			return (_get_line(&bkup));
	}
	return (0);
}
