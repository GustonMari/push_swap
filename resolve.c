/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:01:01 by gmary             #+#    #+#             */
/*   Updated: 2021/12/22 13:26:13 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// faire le double chainage pour scanner par la fin
#include <stdio.h>

void	ft_resolve_a(t_list	**head_a, t_list **head_b, int chunk)
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
		ft_pb(head_a, head_b, chunk);
	while (ft_lstlast(*head_a)->content < mid)
	{
		ft_rra(head_a);
		ft_pb(head_a, head_b, chunk);
	}
	while (ft_all_below_mid(*head_a, mid) != 1)
	{
		while ((*head_a)->content >= mid)
			ft_ra(head_a);
		while ((*head_a)->content < mid)
			ft_pb(head_a, head_b, chunk);
	}
	ft_resolve_a(head_a, head_b, chunk + 1);
}

//void	ft_resolve_connect(t_list	**head_a, t_list **head_b, int chunk)
//{
//	if (ft_chunk_size(chunk) == 1)
//		pa(head_a, head_b, chunk);
//	if (ft_chunk_size(chunk) == 2)
//	{	ft_solve_two(head_a);
//		// et 2 pa pour envoyer le res
//	}
//	// faire une fonction pour 5 aussi ??
//	ft_resolve_b(head_a, head_b, chunk);
//}

//void	ft_resolve_b(t_list	**head_a, t_list **head_b, int chunk)
//{
//	int		mid;
//	t_list	*temp;
//	// surement passer par une valeur temp pour leak avec med_position
//	temp = *head_b;
//	mid = ft_med_position(&temp);
//	free(temp);
//	if (ft_chunk_size(chunk) == 1)
//	{
//		ft_pa(head_a, head_b, chunk);
//		ft_resolve_b(head_a, head_b, chunk - 1);
//	}
//	if (ft_lstsize(*head_b) == 0)
//		return ;
//	while ((*head_b)->content >= mid) && ((*head_b)->chunk_index == chunk))
//		ft_pa(head_a, head_b);
//	//while (ft_lstlast(*head_b)->content < mid)
//	//{
//	//	//on utilise rra car utilisable pour a et b
//	//	ft_rra(head_b);
//	//	ft_pa(head_a, head_b);
//	//}
//	//while (ft_all_below_mid(*head_b, mid) != 1)
//	//{
//	//	while ((*head_b)->content >= mid)
//	//		ft_ra(head_b);
//	//	while ((*head_b)->content < mid)
//	//		ft_pa(head_a, head_b);
//	//}
//	ft_resolve_b(head_a, head_b, chunk - 1);
//}

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

int	ft_check_chunk_max(t_list *head)
{
	int	max;

	max = 0;
	while(head)
	{
		if (head->chunk_index >= max)
			max = head->chunk_index;
		head = head->next;
	}
	return (max);
}