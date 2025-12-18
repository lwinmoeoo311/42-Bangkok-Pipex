/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:38:08 by lwoo              #+#    #+#             */
/*   Updated: 2025/08/31 15:33:47 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	int		i;
	int		point;

	res = (char *)s;
	i = 0;
	point = 0;
	while (res[i])
	{
		if (res[i] == (unsigned char)c)
			point = i;
		i++;
	}
	i = 0;
	while (*res)
	{
		if (*res == (unsigned char)c && i == point)
			return (res);
		i++;
		res++;
	}
	if (c == '\0')
		return (res);
	return (0);
}
