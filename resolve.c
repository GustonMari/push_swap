/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:01:01 by gmary             #+#    #+#             */
/*   Updated: 2021/12/21 13:39:22 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// faire le double chainage pour scanner par la fin

void	ft_resolve_a(t_list	**head_a, t_list **head_b)
{
	int	mid;
	t_list *temp;
	// surement passer par une valeur temp pour leak avec med_position
	temp = *head_a;
	mid = ft_med_position(&temp);
	free(temp);	
	//while (ft_already_sort(head_a))
	//{
	while ((*head_a)->content < mid)
		ft_pb(head_a, head_b);
	//temp = *head_a;
	while ((*head_a)->content >= mid)
	{	
		if ((*head_a)->content < mid)
			break;
		if ((*head_a)->content >= mid)
		{	
			printf("mid =%d\n", mid);
			ft_rra(head_a);
		}
		else
			break;
	}
	//temp = *head_a;
		
		
		
	//while ((*head_a))
	//{
	//	printf("%d\n", ((*head_a)->content));
	//	(*head_a) = (*head_a)->next;
	//}
	//printf("liste b\n");
	//while ((*head_b))
	//{
	//	printf("%d\n", (*head_b)->content);
	//	(*head_b) = (*head_b)->next;
	//}
		
		
		
		
		
		
		
		
		
		//while (temp->content < mid)
		//{
		//	ft_rra(head_a);
		//	ft_pb(head_a, head_b);
		//}


	//}
}