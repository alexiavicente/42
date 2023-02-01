/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:15:03 by marvin            #+#    #+#             */
/*   Updated: 2021/11/14 20:15:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srcptr;
	char	*dstptr;
	size_t	i;

	i = 0;
	srcptr = (char *)src;
	dstptr = (char *)dst;
	if (srcptr < dstptr)
		while ((int)(--len) >= 0)
			*(dstptr + len) = *(srcptr + len);
	else
	{
		while (i < len)
		{
			*(dstptr + i) = *(srcptr + i);
			i++;
		}
	}
	return (dst);
}
