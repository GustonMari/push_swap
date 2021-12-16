/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:19:19 by gmary             #+#    #+#             */
/*   Updated: 2021/12/16 07:48:52 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **head)
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
	
}