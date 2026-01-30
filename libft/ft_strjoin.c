/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:47:04 by lwoo              #+#    #+#             */
/*   Updated: 2025/09/03 12:23:32 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		s_len;
	int		j_len;
	int		i;

	s_len = ft_strlen(s1);
	j_len = ft_strlen(s2);
	res = (char *)malloc((s_len + j_len + 1) * sizeof(char));
	i = 0;
	while (!res)
		return (0);
	while (*s1)
	{
		res[i] = (char)*s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		res[i] = (char)*s2;
		i++;
		s2++;
	}
	res[i] = '\0';
	return (res);
}
