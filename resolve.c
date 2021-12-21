/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:01:01 by gmary             #+#    #+#             */
/*   Updated: 2021/12/21 16:35:46 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// faire le double chainage pour scanner par la fin
#include <stdio.h>

void	ft_resolve_a(t_list	**head_a, t_list **head_b)
{
	int		mid;
	t_list	*temp;
	// surement passer par une valeur temp pour leak avec med_position
	temp = *head_a;
	mid = ft_med_position(&temp);
	free(temp);
	if (ft_lstsize(*head_a) == 2)
		return ;
	while ((*head_a)->content < mid)
		ft_pb(head_a, head_b);
	while (ft_lstlast(*head_a)->content < mid)
	{
		ft_rra(head_a);
		ft_pb(head_a, head_b);
	}
	while (ft_all_below_mid(*head_a, mid) != 1)
	{
		while ((*head_a)->content >= mid)
			ft_ra(head_a);
		while ((*head_a)->content < mid)
			ft_pb(head_a, head_b);
	}
	ft_resolve_a(head_a, head_b);
	//cree un fonction gerant a la fois resolva a et b et qui trie les deux chiffres restant dansla stack a ou b
}

void	ft_resolve_b(t_list	**head_a, t_list **head_b)
{
	int		mid;
	t_list	*temp;
	// surement passer par une valeur temp pour leak avec med_position
	temp = *head_b;
	mid = ft_med_position(&temp);
	free(temp);
	if (ft_lstsize(*head_b) == 2)
		return ;
	while ((*head_b)->content >= mid)
		ft_pa(head_a, head_b);
	//while (ft_lstlast(*head_b)->content < mid)
	//{
	//	//on utilise rra car utilisable pour a et b
	//	ft_rra(head_b);
	//	ft_pa(head_a, head_b);
	//}
	//while (ft_all_below_mid(*head_b, mid) != 1)
	//{
	//	while ((*head_b)->content >= mid)
	//		ft_ra(head_b);
	//	while ((*head_b)->content < mid)
	//		ft_pa(head_a, head_b);
	//}
	//ft_resolve_b(head_a, head_b);
}

int	ft_all_below_mid(t_list *head, int mid)
{
	while (head)
	{
		if (head->content < mid)
			return (0);
		head = head->next;
	}
	return (1);
}
