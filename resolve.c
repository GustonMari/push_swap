/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:01:01 by gmary             #+#    #+#             */
/*   Updated: 2022/01/04 15:19:32 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_resolve_case(t_list **head, int chunk)
{
	if (ft_lstsize(*head) == 3)
		return(ft_solve_three(head));
	if (chunk == 2)
		return (ft_solve_two(head));
	if (chunk == 1 )
		return ;
	else
		return (ft_solve_three_begin(head));
}
/*
void	ft_special_case_reverse(t_list **head, int chunk)
{
	if (chunk == 1)
		return ;
	if (chunk == 2)
		return(ft_solve_two_reverse(head));
	else
		return(ft_solve_three_reverse(head));
}
*/
void	ft_resolve_case_reverse(t_list **head, int chunk)
{
	if (ft_lstsize(*head) == 3)
		return(ft_solve_three_reverse(head));
	//if (ft_lstsize(*head) <= 3)
	//	return(ft_special_case_reverse(head, chunk));
	if (chunk == 1)
		return ;
	if (chunk == 2)
		return(ft_solve_two_reverse(head));
	else
		return(ft_solve_three_reverse_begin(head));
	// pas trop necessaire je pense

}

void ft_resolve_a(t_list **stack_a, t_list **stack_b, int count)
{
	int	push_count;
	int	median;
	int	size;
	int	rotate_count;

	push_count = 0;
	size = count;
	rotate_count = 0;
	// attention si mon count est par exemple egal a 2 que faire ??
	if (count <= 3)
		return (ft_resolve_case(stack_a, count));
	median = ft_med_position(*stack_a, count);
	while (count >= 0)
	{
		if (ft_chunk_not_sort(*stack_a, median, count))
		{
			if ((*stack_a)->content < median && ++push_count)
			{
				ft_pb(stack_a, stack_b, 0);//push_b(stack_a, stack_b);
			}
			// a voir si condi en dessous a tej ou pas car pour 12 rajoute operations pour linstant
			//if (ft_lstlast(*stack_a)->content < median && ++push_count)
			//{
			//	ft_rra(stack_a);
			//	ft_pb(stack_a, stack_b, 0);//push_b(stack_a, stack_b);
			//}
			else
			{
				ft_ra(stack_a);//rotate_a(stack_a);
				rotate_count++;
			}
		}
		count--;
	}
	while (rotate_count-- && ft_lstsize(*stack_a) != size - push_count)
		ft_rra(stack_a);//reverse_rotate_a(stack_a);
	ft_resolve_a(stack_a, stack_b, size - push_count);
	ft_resolve_b(stack_a, stack_b, push_count);
	while (push_count--)
		ft_pa(stack_a, stack_b, 0);//push_a(stack_a, stack_b);
}


void ft_resolve_b(t_list **stack_a, t_list **stack_b, int count)
{
	int	median;
	int	push_count;
	int	rotate_count;
	int	size;

	push_count = 0;
	size = count;
	rotate_count = 0;
	//surement refaire fonction pour le return ici
	if (count <= 3)
		return (ft_resolve_case_reverse(stack_b, count));
	median = ft_med_position(*stack_b, count);
	while (count >= 0)
	{
		if (ft_chunk_not_sort_reverse(*stack_b, median, count))
		{
			if ((*stack_b)->content > median && ++push_count)
				ft_pa(stack_a, stack_b, 0);//push_a(stack_a, stack_b);
			else
			{
				ft_rb(stack_b);//rotate_b(stack_b);
				rotate_count++;
			}
		}
		count--;
	}
	ft_resolve_a(stack_a, stack_b, push_count);
	while (rotate_count-- && ft_lstsize(*stack_b) != size - push_count)
		ft_rrb(stack_b);//reverse_rotate_b(stack_b);
	ft_resolve_b(stack_a, stack_b, size - push_count);
	while (push_count--)
		ft_pb(stack_a, stack_b, 0);//push_b(stack_a, stack_b);
}
