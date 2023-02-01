/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:31:26 by marvin            #+#    #+#             */
/*   Updated: 2021/11/16 09:31:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	iterator;

	iterator = 0;
	if (dstsize > 0)
	{
		while ((src[iterator] != 0) && (iterator + 1 < dstsize))
		{
			dst[iterator] = src[iterator];
			iterator++;
		}
		dst[iterator] = '\0';
	}
	while (src[iterator] != 0)
		iterator++;
	return (iterator);
}