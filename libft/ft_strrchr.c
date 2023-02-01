/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:21:58 by marvin            #+#    #+#             */
/*   Updated: 2021/11/16 09:21:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strrchr(char *b, char c)
{
	int		i;
	char	*result;

	if (c == '\0')
		return (b + ft_strlen(b));
	i = 0;
	result = 0;
	while (b[i])
	{
		if (b[i] == c)
			result = &b[i];
		i++;
	}
	return (result);
}