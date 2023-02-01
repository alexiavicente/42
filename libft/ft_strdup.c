/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:39:10 by marvin            #+#    #+#             */
/*   Updated: 2021/11/16 09:39:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	if (!src)
		return (0);
	while (src[i] != '\0')
		i++;
	aux = malloc(i + 1);
	if (aux != 0)
	{
		j = 0;
		while (j < i)
		{
			aux[j] = src[j];
			j++;
		}
		aux[j] = '\0';
	}
	return (aux);
}