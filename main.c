/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:02:36 by gmary             #+#    #+#             */
/*   Updated: 2022/01/07 10:50:56 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dispatch(t_list **head_a, t_list **head_b, t_operation **head_op)
{
	if (ft_lstsize(*head_a) == 2)
		ft_solve_two(head_a, head_op);
	else if (ft_lstsize(*head_a) == 3)
		ft_solve_three(head_a, head_op);
	else
		ft_resolve_a(head_a, head_b, ft_lstsize(*head_a), head_op);
	ft_first_epuration(head_op);
	ft_second_epuration(head_op);
}

int	main(int ac, char **av)
{
	t_list		*head_a;
	t_list		*head_b;
	t_operation	*head_op;

	head_a = NULL;
	head_b = NULL;
	head_op = NULL;
	if (ac == 1 || !ft_check(av))
	{
		write (2, "Error\n", 6);
		return (0);
	}
	if (!ft_create_new(ac, av, &head_a)
		|| (ac != 2 && !ft_already_sort(&head_a))
		|| ft_double(&head_a))
	{
		write (2, "Error\n", 6);
		return (0);
	}
	ft_dispatch(&head_a, &head_b, &head_op);
	ft_print_result(&head_op);
	ft_lstclear_modif(&head_a);
	ft_lstclear_modif_operation(&head_op);
	return (0);
}
