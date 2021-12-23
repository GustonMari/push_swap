/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:13:00 by gmary             #+#    #+#             */
/*   Updated: 2021/12/23 10:07:21 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_two(t_list **head)
{
	if ((*head)->content > (*head)->next->content)
	{
		ft_sa(head);
	}
}

void	ft_solve_two_reverse(t_list **head)
{
	if ((*head)->content < (*head)->next->content)
	{
		ft_sa(head);
	}
}

void	ft_solve_three(t_list **head)
{
	int	one;
	int	two;
	int	three;

	one = (*head)->content;
	two = (*head)->next->content;
	three = (*head)->next->next->content;
	if (one > two && two < three && one < three)
		ft_sa(head);
	if (one > two && two > three && one > three)
	{
		ft_sa(head);
		ft_rra(head);
	}
	if (one > two && two < three && one > three)
		ft_ra(head);
	if (one < two && two > three && one < three)
	{
		ft_sa(head);
		ft_ra(head);
	}
	if (one < two && two > three && one > three)
		ft_rra(head);
}
