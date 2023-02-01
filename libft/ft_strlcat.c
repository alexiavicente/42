/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:14:04 by marvin            #+#    #+#             */
/*   Updated: 2021/11/16 09:14:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			j;
	size_t		dst_len;
	size_t		src_len;

	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len + 1)
		return (src_len + size);
	while ((src[j])
		&& ((size - dst_len - 1) > j))
		{
			*(dst + dst_len + j) = src[j];
			j++;
		}
	*(dst + dst_len + j) = '\0';
	return (dst_len + src_len);
}
