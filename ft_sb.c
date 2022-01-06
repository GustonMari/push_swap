/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:52:37 by gmary             #+#    #+#             */
/*   Updated: 2022/01/06 12:05:19 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_list **head, t_operation **head_op)
{
	t_list	*temp;
	t_list	*forward;

	if (!*head || ft_lstsize(*head) == 1)
		return ;
	temp = *head;
	forward = temp;
	forward = forward->next;
	temp->next = forward->next;
	forward->next = temp;
	*head = forward;
	ft_addback_operation(head_op, ft_create_new_operation("sb"));
}
