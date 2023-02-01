/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:40:48 by alexia            #+#    #+#             */
/*   Updated: 2023/02/01 10:41:01 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"



static int	specifier_position(char c, char *spec)
{
	int		pos;

	pos = 0;
	while (spec[pos])
	{
		if (c == spec[pos])
			return (pos);
		pos += 1;
	}
	return (PRINTF_FAILURE);
}



static int	get_specifier(char c, t_attr *attr, char *spec)
{
	int		*corres;
	int		specifier;

	corres = ft_memalloc(sizeof(int) * SPECI_SIZE);
	corres[LOWER_S] = LOW_S_BIT;
	corres[UPPER_S] = UPP_S_BIT;
	corres[LOWER_P] = LOW_P_BIT;
	corres[LOWER_D] = LOW_D_BIT;
	corres[UPPER_D] = UPP_D_BIT;
	corres[LOWER_I] = LOW_I_BIT;
	corres[LOWER_O] = LOW_O_BIT;
	corres[UPPER_O] = UPP_O_BIT;
	corres[LOWER_U] = LOW_U_BIT;
	corres[UPPER_U] = UPP_U_BIT;
	corres[LOWER_X] = LOW_X_BIT;
	corres[UPPER_X] = UPP_X_BIT;
	corres[LOWER_C] = LOW_C_BIT;
	corres[UPPER_C] = UPP_C_BIT;
	corres[LOWER_B] = LOW_B_BIT;
	if (((specifier = specifier_position(c, spec)) != PRINTF_FAILURE) && c)
		attr->flags |= corres[specifier];
	free(corres);
	return (specifier);
}



int			parse_specifier(va_list arg, char **format, t_attr *attr)
{
	int		specifier;
	int		is_valid;
	char	*conversion;

	attr->flags = 0;
	if (!(conversion = (char *)malloc(sizeof(char) * SPECI_SIZE)))
		return (0);
	conversion = ft_strncpy(conversion, SPECIFIERS, SPECI_SIZE);
	specifier = PRINTF_FAILURE;
	while (**format)
	{
		if ((specifier_position(**format, conversion) != PRINTF_FAILURE) \
				&& (specifier = get_specifier(**format, attr, conversion)))
			break ;
		if (!(is_valid = get_attributes(format, arg, attr)))
			break ;
	}
	free(conversion);
	return (specifier);
}