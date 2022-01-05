/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:33:16 by gmary             #+#    #+#             */
/*   Updated: 2022/01/05 09:41:45 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_modif(t_list **lst)
{
	t_list	*temp;

	while ((*lst))
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		temp->content = 0;
		temp->chunk_index = 0;
		free(temp);
	}
}

void	ft_lstclear_modif_operation(t_operation **lst)
{
	t_operation	*temp;

	while ((*lst))
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		//free(temp->operation);
		free(temp);
	}
}