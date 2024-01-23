/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:34:20 by jeshin            #+#    #+#             */
/*   Updated: 2023/10/20 16:07:39 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ret;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (0);
	i = 0;
	while (*s1)
	{
		ret[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		ret[i] = *s2;
		s2++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
