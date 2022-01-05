/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:13:00 by gmary             #+#    #+#             */
/*   Updated: 2022/01/05 09:10:17 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_two(t_list **head, t_operation **head_op)
{
	if ((*head)->content > (*head)->next->content)
	{
		ft_sa(head, head_op);
	}
	//(*head)->chunk_index = -1;
	//(*head)->next->chunk_index = -1;
}

void	ft_solve_two_reverse(t_list **head, t_operation **head_op)
{
	if ((*head)->content < (*head)->next->content)
	{
		ft_sa(head, head_op);
	}
}

void	ft_solve_three(t_list **head, t_operation **head_op)
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
	{
		ft_sa(head, head_op);
		ft_rra(head, head_op);
	}
	if (one > two && two < three && one > three)
		ft_ra(head, head_op);
	if (one < two && two > three && one < three)
	{
		ft_sa(head, head_op);
		ft_ra(head, head_op);
	}
	if (one < two && two > three && one > three)
		ft_rra(head, head_op);
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
	{
		ft_sa(head, head_op);
		ft_ra(head, head_op);
		ft_sa(head, head_op);
		ft_rra(head, head_op);
		ft_sa(head, head_op);
		//ft_sa(head);
		//ft_rra(head);
	}
	if (one > two && two < three && one > three)
	{
		ft_sa(head, head_op);
		ft_ra(head, head_op);
		ft_sa(head, head_op);
		ft_rra(head, head_op);
		//ft_ra(head);
	}
	if (one < two && two > three && one < three)
	{
		ft_ra(head, head_op);
		ft_sa(head, head_op);
		ft_rra(head, head_op);
		//ft_sa(head);
		//ft_ra(head);
	}
	if (one < two && two > three && one > three)
	{
		ft_ra(head, head_op);
		ft_sa(head, head_op);
		ft_rra(head, head_op);
		ft_sa(head, head_op);
		//ft_rra(head);
	}
}

void	ft_solve_three_reverse(t_list **head, t_operation **head_op)
{
	int	one;
	int	two;
	int	three;

	one = (*head)->content;
	two = (*head)->next->content;
	three = (*head)->next->next->content;
	if (one < two && two > three && one > three)
		ft_sa(head, head_op);
	if (one < two && two < three && one < three)
	{
		ft_sa(head, head_op);
		ft_rra(head, head_op);
	}
	if (one < two && two > three && one < three)
		ft_ra(head, head_op);
	if (one > two && two < three && one > three)
	{
		ft_sa(head, head_op);
		ft_ra(head, head_op);
	}
	if (one > two && two < three && one < three)
		ft_rra(head, head_op);
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
		ft_sa(head, head_op);
	if (one < two && two < three && one < three)
	{
		ft_sa(head, head_op);
		ft_ra(head, head_op);
		ft_sa(head, head_op);
		ft_rra(head, head_op);
		ft_sa(head, head_op);
		//ft_sa(head);
		//ft_rra(head);
	}
	if (one < two && two > three && one < three)
	{
		ft_sa(head, head_op);
		ft_ra(head, head_op);
		ft_sa(head, head_op);
		ft_rra(head, head_op);
		//ft_ra(head);
	}
	if (one > two && two < three && one > three)
	{
		ft_ra(head, head_op);
		ft_sa(head, head_op);
		ft_rra(head, head_op);
		//ft_sa(head);
		//ft_ra(head);
	}
	if (one > two && two < three && one < three)
	{
		ft_ra(head, head_op);
		ft_sa(head, head_op);
		ft_rra(head, head_op);
		ft_sa(head, head_op);
			//ft_rra(head);
	}
}