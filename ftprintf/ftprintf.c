/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:35:21 by alexia            #+#    #+#             */
/*   Updated: 2023/02/01 10:37:17 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"


static int	print_no_specifier(char c, t_attr *attr)
{
	int		len;

	if (!(attr->flags & MINUS))
		len = print_spaces(attr->width, sizeof(char), attr->flags);
	ft_putchar(c);
	if (attr->flags & MINUS)
		len = print_spaces(attr->width, sizeof(char), attr->flags);
	return (len);
}



static int	print_specifier(char format, va_list arg, t_attr *attr, int i)
{
	int		print;

	if (i == LOWER_S)
		print = print_string(arg, attr);
	else if (i == UPPER_S)
		print = print_wide_string(arg, attr);
	else if ((i == LOWER_D || i == UPPER_D || i == LOWER_I) \
				|| (i == LOWER_U || i == UPPER_U))
		print = print_decimal(arg, attr);
	else if (i == LOWER_O || i == UPPER_O)
		print = print_octal(arg, attr);
	else if (i == LOWER_P || i == LOWER_X || i == UPPER_X)
		print = print_hexadecimal(arg, attr);
	else if (i == LOWER_C)
		print = print_character(arg, attr);
	else if (i == UPPER_C)
		print = print_wide_character(arg, attr);
	else if (i == LOWER_B)
		print = print_binary(arg, attr);
	else
		print = print_no_specifier(format, attr);
	return (print);
}

/*
** If successful, the total number of characters written is returned.
** On failure, a negative number is returned (defined by PRINTF_FAILURE macro).
*/

static int	print_stdout(const char *format[], va_list arg)
{
	int		specifier;
	t_attr	attribute;

	attribute.flags = 0;
	attribute.width = 0;
	attribute.precision = 0;
	specifier = parse_specifier(arg, (char **)format, &attribute);
	if (!**format)
		return (PRINTF_FAILURE);
	return (print_specifier((char)**format, arg, &attribute, specifier));
}



int			ft_printf(const char *format, ...)
{
	int		len;
	int		count;
	va_list	arg;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += 1;
			if ((len = print_stdout(&format, arg)) == PRINTF_FAILURE)
				break ;
			count += len;
		}
		else
		{
			ft_putchar(*format);
			count += 1;
		}
		format += 1;
	}
	va_end(arg);
	return (count);
}