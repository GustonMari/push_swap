/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:33:50 by gmary             #+#    #+#             */
/*   Updated: 2022/01/05 18:31:47 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_list **head_a, t_list **head_b, int chunk, t_operation **head_o)
{
	t_list	*temp;
	t_list	*swap;

	// on a que ca comme securite ??
	if(!*head_a)
		return ;
	if (ft_lstsize(*head_a) != 1)
	{
		temp = *head_a;
		temp = temp->next;
	}
	swap = (*head_a);
	swap->next = *head_b;
	// voir si tej chunk ligne
	swap->chunk_index = chunk;
	*head_b = swap;
	*head_a = NULL;
	if (ft_lstsize(*head_a) != 1)
		*head_a = temp;
	ft_addback_operation(head_o, ft_create_new_operation("pb"));
}
/*
void	ft_pb(t_list **head_a, t_list **head_b)
{
	t_list	*temp;
	t_list	*swap;

	// on a que ca comme securite ??
	if(!*head_a)
		return ;
	if (ft_lstsize(*head_a) != 1)
	{
		temp = *head_a;
		temp = temp->next;
	}
	swap = (*head_a);
	swap->next = *head_b;
	*head_b = swap;
	*head_a = NULL;
	if (ft_lstsize(*head_a) != 1)
		*head_a = temp;
}
*/