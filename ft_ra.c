/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:46:42 by gmary             #+#    #+#             */
/*   Updated: 2021/12/16 10:08:36 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **head)
{
	t_list	*temp;
	t_list	*new_head;
	t_list	*change;
	
	if (ft_lstsize(*head) == 1)
		return ;
	temp = ft_lstlast(*head);
	new_head = (*head)->next;
	change = *head;
	temp->next = change;
	change->next = NULL;
	*head = new_head;
}