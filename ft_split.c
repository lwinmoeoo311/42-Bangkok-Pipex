/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:29:44 by lwoo              #+#    #+#             */
/*   Updated: 2025/12/11 15:28:09 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

static int	word_count(char *s, char separator)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 1;
	while (*s)
	{
		if (*s != separator && is_word)
		{
			count++;
			is_word = 0;
		}
		else if (*s == separator)
			is_word = 1;
		s++;
	}
	return (count);
}

static char	*fill_word(char *s, char separator)
{
	int		i;
	int		w_len;
	char	*word;

	i = 0;
	w_len = 0;
	while (s[w_len] && s[w_len] != separator)
		w_len++;
	word = (char *)malloc(w_len + 1);
	if (!word)
		return (NULL);
	while (s[i] && i < w_len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char separator)
{
	int		i;
	int		w_count;
	char	**res;

	i = 0;
	w_count = word_count(s, separator);
	res = (char **)malloc((w_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < w_count)
	{
		res[i] = fill_word(s, separator);
		if (!res[i])
			return (NULL);
		s += ft_strlen(res[i]);
		while (*s && *s == separator)
			s++;
		i++;
	}
	res[i] = NULL;
	return (res);
}
