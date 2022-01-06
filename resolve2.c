/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:52:50 by gmary             #+#    #+#             */
/*   Updated: 2022/01/06 16:05:12 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_end_b(t_list **h_a, t_list **h_b, t_operation **h_o, int push)
{
	while (push--)
		ft_pb(h_a, h_b, h_o);
}

void	ft_res_b(t_list **h_a, t_list **h_b, int count, t_operation **h_o)
{
	int	median;
	int	push_count;
	int	rotate_count;
	int	size;

	push_count = 0;
	size = count;
	rotate_count = 0;
	median = ft_med_position(*h_b, count);
	while (count >= 0)
	{
		if (ft_chunk_not_sort_reverse(*h_b, median, count))
		{
			if ((*h_b)->content > median && ++push_count)
				ft_pa(h_a, h_b, h_o);
			else
				rotate_count += ft_rb(h_b, h_o);
		}
		count--;
	}
	ft_resolve_a(h_a, h_b, push_count, h_o);
	while (rotate_count-- && ft_lstsize(*h_b) != size - push_count)
		ft_rrb(h_b, h_o);
	ft_resolve_b(h_a, h_b, size - push_count, h_o);
	ft_push_end_b(h_a, h_b, h_o, push_count);
}

void	ft_resolve_b(t_list **h_a, t_list **h_b, int count, t_operation **h_o)
{
	if (count <= 3)
		return (ft_resolve_case_reverse(h_b, count, h_o));
	ft_res_b(h_a, h_b, count, h_o);
}
