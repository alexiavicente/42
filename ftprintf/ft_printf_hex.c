/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:37:44 by alexia            #+#    #+#             */
/*   Updated: 2023/02/01 10:37:57 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"


static char	*get_hex_nbr(uintmax_t nbr, char *hex, char *hex_str)
{
	int		i;
	int		len;

	i = 0;
	len = !nbr ? 1 : 0;
	while (nbr)
	{
		hex[len++] = hex_str[nbr & 0xF];
		nbr >>= 4;
	}
	while (i < (len / 2))
	{
		hex[i] ^= hex[len - i - 1];
		hex[len - i - 1] ^= hex[i];
		hex[i] ^= hex[len - i - 1];
		i += 1;
	}
	return (hex);
}


static int	hex_nbr_digits(uintmax_t nbr)
{
	int		len;

	len = !nbr ? 1 : 0;
	while (nbr)
	{
		len += 1;
		nbr >>= 4;
	}
	return (len);
}



static char	*conv_hex(uintmax_t nbr, int *nbr_digits)
{
	char	*hex_nbr;
	char	*hex_str;

	*nbr_digits = hex_nbr_digits(nbr);
	if (!(hex_nbr = ft_memalloc(sizeof(char) * (*nbr_digits) + 1)))
		return (NULL);
	*hex_nbr = '0';
	if (!(hex_str = ft_strdup("0123456789ABCDEF")))
		return (NULL);
	hex_nbr = get_hex_nbr(nbr, hex_nbr, hex_str);
	free(hex_str);
	return (hex_nbr);
}



int			print_hexadecimal(va_list ap, t_attr *attr)
{
	int		len;

	len = 0;
	if (attr->flags & LOW_P_BIT)
		len = format_unsigned((uintmax_t)va_arg(ap, void *), attr, &conv_hex);
	else if (attr->flags & J)
		len = format_unsigned(va_arg(ap, uintmax_t), attr, &conv_hex);
	else if (attr->flags & Z)
		len = format_unsigned(va_arg(ap, size_t), attr, &conv_hex);
	else if (attr->flags & LL)
		len = format_unsigned(va_arg(ap, unsigned long long), attr, &conv_hex);
	else if (attr->flags & L)
		len = format_unsigned(va_arg(ap, unsigned long), attr, &conv_hex);
	else if (attr->flags & H)
		len = format_unsigned((unsigned short)va_arg(ap, unsigned int), attr,
			&conv_hex);
	else if (attr->flags & HH)
		len = format_unsigned((unsigned char)va_arg(ap, unsigned int), attr,
			&conv_hex);
	else
		len = format_unsigned(va_arg(ap, unsigned int), attr, &conv_hex);
	return (len);
}