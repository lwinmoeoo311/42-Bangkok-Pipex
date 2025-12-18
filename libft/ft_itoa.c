/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:12:21 by lwoo              #+#    #+#             */
/*   Updated: 2025/09/04 15:32:50 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (++len);
}

char	*ft_itoa(int n)
{
	int		num_len;
	long	num;
	char	*res;

	num_len = ft_numlen(n);
	res = (char *)malloc(num_len + 1);
	num = n;
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	if (n == 0)
		res[0] = '0';
	res[num_len] = '\0';
	while (num > 0)
	{
		res[--num_len] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
