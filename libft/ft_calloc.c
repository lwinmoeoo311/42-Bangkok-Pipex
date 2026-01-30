/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 02:08:24 by lwoo              #+#    #+#             */
/*   Updated: 2025/09/05 04:50:54 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t			total;
	size_t			counter;
	unsigned char	*ptr;

	if (nelem == 0 || elsize == 0)
		return (malloc(0));
	if (nelem > (size_t)-1 / elsize)
		return (0);
	total = nelem * elsize;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	counter = 0;
	while (counter < nelem * elsize)
	{
		ptr[counter] = 0;
		counter++;
	}
	return (ptr);
}
