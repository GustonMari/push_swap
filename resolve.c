/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:01:01 by gmary             #+#    #+#             */
/*   Updated: 2021/12/23 15:37:58 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// faire le double chainage pour scanner par la fin
#include <stdio.h>

void ft_resolve_a(t_list **head_a, t_list **head_b, int chunk)
{
	int mid;
	t_list *temp;
	// surement passer par une valeur temp pour leak avec med_position
	temp = *head_a;
	mid = ft_med_position(&temp);
	//free(temp);
	if (ft_lstsize(*head_a) == 2)
		return;
	while ((*head_a)->content < mid)
		ft_pb(head_a, head_b, chunk);
	while (ft_lstlast(*head_a)->content < mid)
	{
		ft_rra(head_a);
		ft_pb(head_a, head_b, chunk);
	}
	while (ft_all_below_mid(*head_a, mid, chunk) != 1)
	{
		while ((*head_a)->content >= mid)
			ft_ra(head_a);
		while ((*head_a)->content < mid)
			ft_pb(head_a, head_b, chunk);
	}
	ft_resolve_a(head_a, head_b, chunk + 1);
}

int	ft_resolve_connect(t_list **head_a, t_list **head_b, int chunk)
{
	if (ft_chunk_size(*head_b, chunk) == 1)
	{
		ft_pa(head_a, head_b, chunk);
		return (1);
	}
	if (ft_chunk_size(*head_b, chunk) == 2)
	{
		ft_solve_two_reverse(head_b);
		ft_pa(head_a, head_b, chunk);
		ft_pa(head_a, head_b, chunk);
		return (1);
	}
	return (0);
}

void ft_resolve_b(t_list **head_a, t_list **head_b, int chunk)
{
	int		mid;
	t_list	*temp;
	int		count;
	
	count = 0;
	if (ft_lstsize(*head_b) == 0 || chunk < 0)
		return;
	if (ft_lstsize(*head_b) == 1)
	{	
		ft_pa(head_a, head_b, chunk+3);
		return ;
	}
	if (ft_resolve_connect(head_a, head_b, chunk) == 1)
		chunk--;
	temp = *head_b;
	mid = ft_med_position_chunk(&temp,chunk);
	while (ft_all_above_mid(*head_b, mid, chunk) == 0)
	{
		if ((*head_b)->content >= mid && (*head_b)->chunk_index == chunk)
			ft_pa(head_a, head_b, chunk+3);
		if ((*head_b)->content < mid && (*head_b)->chunk_index == chunk)
		{
			ft_ra(head_b);
			count++;
		}
	}
	if (ft_chunk_size(*head_b, chunk) > 0)
	{
		while (count > 0 && ft_lstsize(*head_b) != 1)
		{
			ft_rra(head_b);
			count--;
		}
			ft_resolve_b(head_a, head_b, chunk);
	}
	//while ((*head_b)->content >= mid && (*head_b)->chunk_index == chunk)
	//	ft_pa(head_a, head_b, chunk);
	//while ((*head_b)->content < mid && (*head_b)->chunk_index == chunk)
	//{
	//	ft_ra(head_b);
	//	count++;
	//}
	//// siil ne reste plus rien au dessus du mid alors et que chunk pas vid on reverse ATTEMTION PAS SUR POUR LA TAILLE DE SIZE PLUSTOT 0 OU 2 ???
	//if (ft_all_above_mid(*head_b, mid, chunk) == 1 && ft_chunk_size(*head_b, chunk) > 0)
	//{
	//	while (count > 0)
	//	{
	//		ft_rra(head_b);
	//		count--;
	//	}
	//	ft_resolve_a(head_a, head_b, chunk);
	//}
	//else
	//	ft_resolve_a(head_a, head_b, chunk - 1);
}

/*
void ft_resolve_b(t_list **head_a, t_list **head_b, int chunk)
{
	int		mid;
	t_list *temp;
	// surement passer par une valeur temp pour leak avec med_position

	if (ft_lstsize(*head_b) == 0 || chunk < 0)
		return;
	if (ft_chunk_size(*head_b, chunk) == 1)
	{
		ft_pa(head_a, head_b, chunk);
		chunk--;
	}
	printf("chunk     %d\n", chunk);
	temp = (*head_b);
	mid = ft_med_position_chunk(&temp, chunk);
	//free(temp);
	printf("mid			%d\n", mid);
	while (((*head_b)->content >= mid) && ((*head_b)->chunk_index == chunk))
		ft_pa(head_a, head_b, chunk);
	
	
	if (ft_chunk_size(*head_b, chunk) == 2)
	{
		ft_solve_two_reverse(head_b);
		ft_pa(head_a, head_b, chunk);
		ft_pa(head_a, head_b, chunk);
		ft_resolve_b(head_a, head_b, chunk - 1);
	}
	
	//faire un if pour savoir si il reste des elements dun chunk a trie 
	//et faire recursion dans ce cas chunk et pas chunk - 1;
	
	//while (ft_lstlast(*head_b)->content < mid && (ft_lstlast(*head_b)->chunk_index == chunk))
	//{
	//	//on utilise rra car utilisable pour a et b
	//	ft_rra(head_b);
	//	ft_pa(head_a, head_b, chunk);
	//}
	//while (ft_all_below_mid(*head_b, mid) != 1)
	//{
	//	while ((*head_b)->content >= mid)
	//		ft_ra(head_b);
	//	while ((*head_b)->content < mid)
	//		ft_pa(head_a, head_b);
	//}
	ft_resolve_b(head_a, head_b, chunk - 1);
}
*/
int ft_all_below_mid(t_list *head, int mid, int chunk)
{
	while (head)
	{
		if (head->content < mid && (head)->chunk_index == chunk)
			return (0);
		head = head->next;
	}
	return (1);
}

int ft_all_above_mid(t_list *head, int mid, int chunk)
{
	while (head)
	{
		if (head->content >= mid && (head)->chunk_index == chunk)
			return (0);
		head = head->next;
	}
	return (1);
}


int ft_check_chunk_max(t_list *head)
{
	int max;

	max = 0;
	while (head)
	{
		if (head->chunk_index >= max)
			max = head->chunk_index;
		head = head->next;
	}
	return (max);
}