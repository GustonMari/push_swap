/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:51:12 by gmary             #+#    #+#             */
/*   Updated: 2022/01/04 14:52:20 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_list **head)
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
	write(1, "rrb\n", 4);
}