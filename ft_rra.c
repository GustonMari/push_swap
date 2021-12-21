/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:04:58 by gmary             #+#    #+#             */
/*   Updated: 2021/12/21 13:32:40 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **head)
{
	t_list	*temp;
	t_list	*before_last;
	int		size;
	int		i;

	size = 0;
	i = 1;
	temp = ft_lstlast(*head);
	size = ft_lstsize(*head);
	before_last = *head;
	while(i < size -1)
	{
		//check si segfault possible pour size = 1; 
		before_last = before_last->next;
		i++;
	}
	temp->next = *head;
	before_last->next = NULL;
	*head = temp;
}

/*
void	ft_rra(t_list **head)
{
	t_list	*tmp;
	t_list	*swap;

	if ((*head) && (*head)->next)
	{
		swap = (*head);
		while ((*head)->next->next)
		{
			(*head) = (*head)->next;
		}
		tmp = (*head)->next;
		(*head)->next = NULL;
		(*head) = swap;
		tmp->next = (*head);
		(*head) = tmp;
	}
}
*/
