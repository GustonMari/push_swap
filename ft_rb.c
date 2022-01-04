/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:50:05 by gmary             #+#    #+#             */
/*   Updated: 2022/01/04 14:50:45 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_list **head)
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
	write(1, "rb\n", 3);
}