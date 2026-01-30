/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:27:42 by lwoo              #+#    #+#             */
/*   Updated: 2025/09/03 17:19:35 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*skip_leading(const char *s, const char *set)
{
	while (*s && ft_strchr(set, *s))
		s++;
	return (s);
}

size_t	skip_trailing(const char *s, const char *set)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0 && ft_strchr(set, s[len - 1]))
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	size_t		trimmed_len;
	char		*result;

	if (!s1 || !set)
		return (NULL);
	start = skip_leading(s1, set);
	trimmed_len = skip_trailing(start, set);
	result = (char *)malloc(trimmed_len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, start, trimmed_len + 1);
	return (result);
}
