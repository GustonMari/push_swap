/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:52:37 by gmary             #+#    #+#             */
/*   Updated: 2022/01/04 14:53:21 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_list **head)
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
	write(1, "sb\n", 3);
}