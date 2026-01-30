/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:26:11 by lwoo              #+#    #+#             */
/*   Updated: 2025/09/02 17:57:13 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = (int)ft_strlen((char *)s);
	if (start >= src_len)
	{
		res = (char *)ft_calloc(1, sizeof(char));
		if (!res)
			return (0);
		return (res);
	}
	if (len >= src_len)
		len = src_len - start;
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	while (i < len && s[start + i])
	{
		res[i] = (char)s[start + i];
		i++;
	}
	return (res);
}
