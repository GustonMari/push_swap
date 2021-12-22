/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:57:28 by gmary             #+#    #+#             */
/*   Updated: 2021/12/22 10:53:23 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ne marche pas lorsque la liste b est seulement dun content */

void	ft_pa(t_list **head_a, t_list **head_b, int chunk)
{
	t_list	*temp;
	t_list	*swap;
	// on a que ca comme securite ??
	
	if(!*head_b)
		return ;
	if (ft_lstsize(*head_b) != 1)
	{
		temp = *head_b;
		temp = temp->next;
	}
	swap = (*head_b);
	(swap)->next = *head_a;
		// voir si tej chunk ligne
	swap->chunk_index = chunk;
	*head_a = swap;
	(*head_b) = NULL;
	if (ft_lstsize(*head_b) <= 1)
		*head_b = temp;
}