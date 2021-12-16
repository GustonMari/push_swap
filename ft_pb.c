/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:33:50 by gmary             #+#    #+#             */
/*   Updated: 2021/12/16 09:56:50 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ne marche pas lorsque la liste b est seulement dun content */

void	ft_pb(t_list **head_a, t_list **head_b)
{
	t_list	*temp;

	// on a que ca comme securite ??
	if(!*head_a)
		return ;
	if (ft_lstsize(*head_a) != 1)
	{
		temp = *head_a;
		temp = temp->next;
	}
	(*head_a)->next = *head_b;
	*head_b = *head_a;
	*head_a = NULL;
	if (ft_lstsize(*head_a) != 1)
		*head_a = temp;
}