/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_case3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:20:16 by gmary             #+#    #+#             */
/*   Updated: 2022/01/06 12:28:12 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case_1_b(t_list **head, t_operation **head_op)
{
	ft_sb(head, head_op);
	ft_rb(head, head_op);
	ft_sb(head, head_op);
	ft_rrb(head, head_op);
	ft_sb(head, head_op);
}

void	ft_case_2_b(t_list **head, t_operation **head_op)
{
	ft_sb(head, head_op);
	ft_rb(head, head_op);
	ft_sb(head, head_op);
	ft_rrb(head, head_op);
}

void	ft_case_3_b(t_list **head, t_operation **head_op)
{
	ft_rb(head, head_op);
	ft_sb(head, head_op);
	ft_rrb(head, head_op);
}

void	ft_case_4_b(t_list **head, t_operation **head_op)
{
	ft_rb(head, head_op);
	ft_sb(head, head_op);
	ft_rrb(head, head_op);
	ft_sb(head, head_op);
}

void	ft_solve_three_reverse_begin(t_list	**head, t_operation **head_op)
{
	int	one;
	int	two;
	int	three;

	one = (*head)->content;
	two = (*head)->next->content;
	three = (*head)->next->next->content;
	if (one < two && two > three && one > three)
		ft_sb(head, head_op);
	if (one < two && two < three && one < three)
		ft_case_1_b(head, head_op);
	if (one < two && two > three && one < three)
		ft_case_2_b(head, head_op);
	if (one > two && two < three && one > three)
		ft_case_3_b(head, head_op);
	if (one > two && two < three && one < three)
		ft_case_4_b(head, head_op);
}
