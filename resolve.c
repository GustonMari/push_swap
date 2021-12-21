/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:01:01 by gmary             #+#    #+#             */
/*   Updated: 2021/12/21 14:59:32 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// faire le double chainage pour scanner par la fin
#include <stdio.h>

void	ft_resolve_a(t_list	**head_a, t_list **head_b)
{
	int		mid;
	t_list	*temp;
	int		middle_size;
	// surement passer par une valeur temp pour leak avec med_position
	temp = *head_a;
	mid = ft_med_position(&temp);
	middle_size = ft_lstsize(temp);
	free(temp);
	//if (ft_lstsize(*head_a) == 2)
	//	return ;
	while (ft)
	{}
		while ((*head_a)->content < mid)
			ft_pb(head_a, head_b);
		while (ft_lstlast(*head_a)->content < mid)
		{
			ft_rra(head_a);
			ft_pb(head_a, head_b);
		}
		while ((*head_a)->content >= mid)
			ft_ra(head_a);
		while ((*head_a)->content < mid)
			ft_pb(head_a, head_b);
	}	
	//ft_resolve_a(head_a, head_b);
}

