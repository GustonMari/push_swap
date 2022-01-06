/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_case2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:08:00 by gmary             #+#    #+#             */
/*   Updated: 2022/01/06 12:27:34 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case_1_a(t_list **head, t_operation **head_op)
{
	ft_sa(head, head_op);
	ft_ra(head, head_op);
	ft_sa(head, head_op);
	ft_rra(head, head_op);
	ft_sa(head, head_op);
}

void	ft_case_2_a(t_list **head, t_operation **head_op)
{
	ft_sa(head, head_op);
	ft_ra(head, head_op);
	ft_sa(head, head_op);
	ft_rra(head, head_op);
}

void	ft_case_3_a(t_list **head, t_operation **head_op)
{
	ft_ra(head, head_op);
	ft_sa(head, head_op);
	ft_rra(head, head_op);
}

void	ft_case_4_a(t_list **head, t_operation **head_op)
{
	ft_ra(head, head_op);
	ft_sa(head, head_op);
	ft_rra(head, head_op);
	ft_sa(head, head_op);
}

void	ft_solve_three_begin(t_list	**head, t_operation **head_op)
{
	int	one;
	int	two;
	int	three;

	one = (*head)->content;
	two = (*head)->next->content;
	three = (*head)->next->next->content;
	if (one > two && two < three && one < three)
		ft_sa(head, head_op);
	if (one > two && two > three && one > three)
		ft_case_1_a(head, head_op);
	if (one > two && two < three && one > three)
		ft_case_2_a(head, head_op);
	if (one < two && two > three && one < three)
		ft_case_3_a(head, head_op);
	if (one < two && two > three && one > three)
		ft_case_4_a(head, head_op);
}
