/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:22:10 by marvin            #+#    #+#             */
/*   Updated: 2021/11/16 10:22:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;
	int		size;

	size = ft_strlen(s);
	result = malloc(size + 1);
	if (result == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, (char) s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
