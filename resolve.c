/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:01:01 by gmary             #+#    #+#             */
/*   Updated: 2022/01/06 12:42:19 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_resolve_case(t_list **head, int chunk, t_operation **head_op)
{
	if (ft_lstsize(*head) == 3)
		return (ft_solve_three(head, head_op));
	if (chunk == 2)
		return (ft_solve_two(head, head_op));
	if (chunk == 1)
		return ;
	else
		return (ft_solve_three_begin(head, head_op));
}

void	ft_resolve_case_reverse(t_list **head, int chunk, t_operation **head_op)
{
	if (ft_lstsize(*head) == 3)
		return (ft_solve_three_reverse(head, head_op));
	if (chunk == 1)
		return ;
	if (chunk == 2)
		return (ft_solve_two_reverse(head, head_op));
	else
		return (ft_solve_three_reverse_begin(head, head_op));
}

void	ft_resolve_a(t_list **stack_a, t_list **stack_b, int count, t_operation **head_op)
{
	int	push_count;
	int	median;
	int	size;
	int	rotate_count;

	push_count = 0;
	size = count;
	rotate_count = 0;
	if (count <= 3)
		return (ft_resolve_case(stack_a, count, head_op));
	median = ft_med_position(*stack_a, count);
	while (count >= 0)
	{
		if (ft_chunk_not_sort(*stack_a, median, count))
		{
			if ((*stack_a)->content < median && ++push_count)
				ft_pb(stack_a, stack_b, 0, head_op);
			else
			{
				ft_ra(stack_a, head_op);
				rotate_count++;
			}
		}
		count--;
	}
	while (rotate_count-- && ft_lstsize(*stack_a) != size - push_count)
		ft_rra(stack_a, head_op);
	ft_resolve_a(stack_a, stack_b, size - push_count, head_op);
	ft_resolve_b(stack_a, stack_b, push_count, head_op);
	while (push_count--)
		ft_pa(stack_a, stack_b, 0, head_op);
}


void ft_resolve_b(t_list **stack_a, t_list **stack_b, int count, t_operation **head_op)
{
	int	median;
	int	push_count;
	int	rotate_count;
	int	size;

	push_count = 0;
	size = count;
	rotate_count = 0;
	if (count <= 3)
		return (ft_resolve_case_reverse(stack_b, count, head_op));
	median = ft_med_position(*stack_b, count);
	while (count >= 0)
	{
		if (ft_chunk_not_sort_reverse(*stack_b, median, count))
		{
			if ((*stack_b)->content > median && ++push_count)
				ft_pa(stack_a, stack_b, 0, head_op);
			else
			{
				ft_rb(stack_b, head_op);
				rotate_count++;
			}
		}
		count--;
	}
	ft_resolve_a(stack_a, stack_b, push_count, head_op);
	while (rotate_count-- && ft_lstsize(*stack_b) != size - push_count)
		ft_rrb(stack_b, head_op);
	ft_resolve_b(stack_a, stack_b, size - push_count, head_op);
	while (push_count--)
		ft_pb(stack_a, stack_b, 0, head_op);
}
