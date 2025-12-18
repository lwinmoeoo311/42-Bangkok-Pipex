/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 01:05:32 by lwoo              #+#    #+#             */
/*   Updated: 2025/09/15 17:05:44 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*receiver;
	unsigned int	i;

	ptr = (unsigned char *)src;
	receiver = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		receiver[i] = (unsigned char)ptr[i];
		i++;
	}
	return (dest);
}
