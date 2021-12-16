/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:20:25 by gmary             #+#    #+#             */
/*   Updated: 2021/12/16 07:01:52 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_elem;
	t_list	*cpy_lst;

	head = NULL;
	cpy_lst = lst;
	while (cpy_lst)
	{
		new_elem = ft_lstnew(f(cpy_lst->content));
		if (!new_elem)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_elem);
		cpy_lst = cpy_lst->next;
	}
	return (head);
}
