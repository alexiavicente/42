/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:35:39 by marvin            #+#    #+#             */
/*   Updated: 2021/11/14 19:35:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		getnumsize(int n);
void	writenum(char *result, int num);
void	rev_array(char *result);

char	*ft_itoa(int n)
{
	int		size;
	int		negative;
	char	*result;

	size = 0;
	negative = 0;
	if (n < 0)
		negative = 1;
	size += getnumsize(n);
	result = ft_calloc(size + negative + 1, 1);
	if (result)
		writenum(result, n);
	return (result);
}

int	getnumsize(int n)
{
	int	result;

	result = 1;
	while (n > 10)
		result += getnumsize(n / 10);
	return (result);
}

void	writenum(char *result, int num)
{
	int	sign;
	int	i;

	sign = 0;
	i = 0;
	if (num < 0)
	{
		sign = 1;
		if (-2147483648 == num)
		{
			result[0] = 8 + '0';
			num /= 10;
			i ++;
		}
		num *= -1;
	}
	while (num > 0)
	{
		result[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	if (sign == 1)
		result[i] = '-';
	rev_array(result);
}

void	rev_array(char *result)
{
	int		size;
	int		i;
	char	aux;

	size = ft_strlen(result) - 1;
	i = 0;
	while (i < size)
	{
		aux = result[i];
		result[i] = result[size];
		result[size] = aux;
		i ++;
		size--;
	}
}