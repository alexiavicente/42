/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:31:27 by marvin            #+#    #+#             */
/*   Updated: 2021/11/14 19:31:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include<unistd.h>

int	number(char *str);

int	ft_atoi(const char *str)
{
	char	mychar;
	int		num;
	int		count;

	count = 0;
	mychar = *str;
	while ((mychar <= '\r' && mychar >= '\t') || mychar == ' ')
	{
		str++;
		mychar = *str;
	}
	if (mychar == '-')
	{
		count ++;
		str++;
	}
	if (mychar == '+')
		str++;
	num = number((char *)str);
	if (count == 1)
		num = num * -1;
	return (num);
}

int	number(char *str)
{
	int		num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10;
		num += *str - '0';
		str++;
	}
	return (num);
}