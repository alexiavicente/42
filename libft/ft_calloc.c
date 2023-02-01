/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:49:47 by marvin            #+#    #+#             */
/*   Updated: 2021/11/16 09:49:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;

	p = malloc(nmemb * size);
	ft_bzero(p, nmemb);
	return (p);
}
/*
printf("postmalloc\n");
	ft_memset(p, 0, nmemb);
	printf("postmemset\n");*/
