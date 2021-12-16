/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:57:28 by gmary             #+#    #+#             */
/*   Updated: 2021/12/16 10:41:39 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* ne marche pas lorsque la liste b est seulement dun content */

void	ft_pa(t_list **head_a, t_list **head_b)
{
	t_list	*temp;

	// on a que ca comme securite ??
	if(!*head_b)
		return ;
	if (ft_lstsize(*head_b) != 1)
	{
		temp = *head_b;
		temp = temp->next;
	}
	(*head_b)->next = *head_a;
	*head_a = *head_b;
	(*head_b) = NULL;
	//printf("size %d\n", ft_lstsize(*head_b));
	//printf("content %s\n", (char *)(*head_b)->content);
	if (ft_lstsize(*head_b) <= 1)
		*head_b = temp;
}