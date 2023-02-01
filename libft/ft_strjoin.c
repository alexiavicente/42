/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:01:32 by marvin            #+#    #+#             */
/*   Updated: 2021/11/16 10:01:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"
#include <stdlib.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = ((char *) s1)[i];
		i++;
	}
	while (s2[j])
	{
		result[i] = ((char *) s2)[j];
		i++;
		j++;
	}
	result[i] = 0;
	return (result);
}