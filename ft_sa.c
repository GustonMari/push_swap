/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:19:19 by gmary             #+#    #+#             */
/*   Updated: 2022/01/05 16:33:02 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **head, t_operation **head_op)
{

	t_list	*temp;
	t_list	*forward;

	//check si condi ok ou pas
	if(!*head || ft_lstsize(*head) == 1)
		return ;
	temp = *head;
	forward = temp;
	forward = forward->next;
	temp->next = forward->next;
	forward->next = temp;
	*head = forward;
	ft_addback_operation(head_op, ft_create_new_operation("sa"));
}