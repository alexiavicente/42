/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arturo <Arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:21:59 by alvicent          #+#    #+#             */
/*   Updated: 2022/03/30 10:35:55 by Arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	 t_list	*ret;

	ret = (t_list *)malloc(sizeof(*ret));
	if (ret == 0)
		return (0);
	ret->content = content;
	ret->next = 0;
	return (ret);
}
