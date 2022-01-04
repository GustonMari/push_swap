/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:13:00 by gmary             #+#    #+#             */
/*   Updated: 2022/01/04 14:46:16 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_two(t_list **head)
{
	if ((*head)->content > (*head)->next->content)
	{
		ft_sa(head);
	}
	//(*head)->chunk_index = -1;
	//(*head)->next->chunk_index = -1;
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

void	ft_solve_three_begin(t_list	**head)
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
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
		ft_sa(head);
		//ft_sa(head);
		//ft_rra(head);
	}
	if (one > two && two < three && one > three)
	{
		ft_sa(head);
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
		//ft_ra(head);
	}
	if (one < two && two > three && one < three)
	{
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
		//ft_sa(head);
		//ft_ra(head);
	}
	if (one < two && two > three && one > three)
	{
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
		ft_sa(head);
		//ft_rra(head);
	}
}

void	ft_solve_three_reverse(t_list **head)
{
	int	one;
	int	two;
	int	three;

	one = (*head)->content;
	two = (*head)->next->content;
	three = (*head)->next->next->content;
	if (one < two && two > three && one > three)
		ft_sa(head);
	if (one < two && two < three && one < three)
	{
		ft_sa(head);
		ft_rra(head);
	}
	if (one < two && two > three && one < three)
		ft_ra(head);
	if (one > two && two < three && one > three)
	{
		ft_sa(head);
		ft_ra(head);
	}
	if (one > two && two < three && one < three)
		ft_rra(head);
}

void	ft_solve_three_reverse_begin(t_list	**head)
{
		int	one;
	int	two;
	int	three;

	one = (*head)->content;
	two = (*head)->next->content;
	three = (*head)->next->next->content;
	if (one < two && two > three && one > three)
		ft_sa(head);
	if (one < two && two < three && one < three)
	{
		ft_sa(head);
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
		ft_sa(head);
		//ft_sa(head);
		//ft_rra(head);
	}
	if (one < two && two > three && one < three)
	{
		ft_sa(head);
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
		//ft_ra(head);
	}
	if (one > two && two < three && one > three)
	{
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
		//ft_sa(head);
		//ft_ra(head);
	}
	if (one > two && two < three && one < three)
	{
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
		ft_sa(head);
			//ft_rra(head);
	}
}