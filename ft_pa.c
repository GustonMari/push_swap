/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:57:28 by gmary             #+#    #+#             */
/*   Updated: 2022/01/07 11:22:09 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **head_a, t_list **head_b, t_operation **head_op)
{
	t_list	*temp;
	t_list	*swap;

	if (!*head_b)
		return ;
	if (ft_lstsize(*head_b) != 1)
	{
		temp = *head_b;
		temp = temp->next;
	}
	swap = (*head_b);
	(swap)->next = *head_a;
	*head_a = swap;
	(*head_b) = NULL;
	if (ft_lstsize(*head_b) <= 1)
		*head_b = temp;
	ft_addback_operation(head_op, ft_create_new_operation("pa"));
}
