/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:46:42 by gmary             #+#    #+#             */
/*   Updated: 2022/01/06 15:57:56 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_list **head, t_operation **head_op)
{
	t_list	*temp;
	t_list	*new_head;
	t_list	*change;

	if (ft_lstsize(*head) == 1)
		return (0);
	temp = ft_lstlast(*head);
	new_head = (*head)->next;
	change = *head;
	temp->next = change;
	change->next = NULL;
	*head = new_head;
	ft_addback_operation(head_op, ft_create_new_operation("ra"));
	return (1);
}
