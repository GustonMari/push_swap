/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:01:01 by gmary             #+#    #+#             */
/*   Updated: 2022/01/06 16:01:25 by gmary            ###   ########.fr       */
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

void	ft_push_end_a(t_list **h_a, t_list **h_b, t_operation **h_o, int push)
{
	while (push--)
		ft_pa(h_a, h_b, h_o);
}

int	ft_res_a(t_list **h_a, t_list **h_b, int count, t_operation **h_o)
{
	int	push_count;
	int	median;
	int	size;
	int	rotate_count;

	push_count = 0;
	size = count;
	rotate_count = 0;
	median = ft_med_position(*h_a, count);
	while (count >= 0)
	{
		if (ft_chunk_not_sort(*h_a, median, count))
		{
			if ((*h_a)->content < median && ++push_count)
				ft_pb(h_a, h_b, h_o);
			else
				rotate_count += ft_ra(h_a, h_o);
		}
		count--;
	}
	while (rotate_count-- && ft_lstsize(*h_a) != size - push_count)
		ft_rra(h_a, h_o);
	return (push_count);
}

void	ft_resolve_a(t_list **h_a, t_list **h_b, int count, t_operation **h_o)
{
	int	push_count;
	int	size;

	size = count;
	if (count <= 3)
		return (ft_resolve_case(h_a, count, h_o));
	push_count = ft_res_a(h_a, h_b, count, h_o);
	ft_resolve_a(h_a, h_b, size - push_count, h_o);
	ft_resolve_b(h_a, h_b, push_count, h_o);
	ft_push_end_a(h_a, h_b, h_o, push_count);
}
