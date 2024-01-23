/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:08:11 by jeshin            #+#    #+#             */
/*   Updated: 2023/10/21 19:15:40 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	len_check(char const *s, unsigned int start, size_t *len)
{
	if (start >= ft_strlen(s))
		*len = 0;
	else
	{
		if (start + *len > ft_strlen(s))
			*len = ft_strlen(s) - start;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	len_check(s, start, &len);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (s[i] && j < len)
	{
		if (i >= start)
			ret[j++] = s[i];
		i++;
	}
	ret[j] = 0;
	return (ret);
}
