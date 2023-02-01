/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arturo <Arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:30:03 by alvicent          #+#    #+#             */
/*   Updated: 2022/03/30 10:36:56 by Arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux = malloc(sizeof(aux));

	if (f == 0 || del == 0)
		return (0);
	while (lst != 0)
	{
		aux = (t_list *)(f)(lst->content);
		(del)(lst->content);
		lst->content = aux;
		lst = lst->next;
	}
	return (lst);
}