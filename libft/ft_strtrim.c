/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:23:34 by marvin            #+#    #+#             */
/*   Updated: 2021/11/16 10:23:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

int		findiftrim(char const to_find, char const *array);

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*result;
	int					i;
	unsigned int		start;
	int					end;

	start = 0;
	end = 0;
	i = 0;
	while (s1[i] && findiftrim(s1[i++], set))
		start++;
	i = ft_strlen(s1) - 1;
	while (i > 0 && findiftrim(s1[i--], set))
		end++;
	if ((ft_strlen(s1) - start - end) <= 0)
		return (ft_calloc(1, 1));
	result = ft_substr(s1, start, ft_strlen(s1) - start - end);
	return (result);
}

int	findiftrim(char const to_find, char const *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}
