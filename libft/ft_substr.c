/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:57:54 by marvin            #+#    #+#             */
/*   Updated: 2021/11/16 09:57:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	result = (char *) malloc(len + 1);
	if (result == 0)
		return (0);
	if (ft_strlen(s) < start)
	{
		*result = 0;
		return (result);
	}
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}