/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:02:36 by gmary             #+#    #+#             */
/*   Updated: 2022/01/24 10:37:44 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
		|| ft_double(&head_a))
	{
		write (2, "Error\n", 6);
		return (0);
	}
	if (ac != 2 && !ft_already_sort(&head_a))
		return (ft_lstclear_modif(&head_a));
	ft_dispatch(&head_a, &head_b, &head_op);
	ft_print_result(&head_op);
	ft_lstclear_modif(&head_a);
	ft_lstclear_modif_operation(&head_op);
	return (0);
}

/*
int	main(int ac, char **av)
{
	t_list		*head_a;
	t_list		*head_b;
	t_operation	*head_op;
	char		**tab;

	head_a = NULL;
	head_b = NULL;
	head_op = NULL;
	tab = ft_split(av[1] , ' ');
	//for (int i = 0; i < 6; i++)
	//	printf("%s|",tab[i]);
	if (ac != 2 || !ft_check(av))
	{
		write (2, "Error\n", 6);
		if (tab)
			ft_clear_tab(tab);
		return (0);
	}
	if (!ft_create_new(ft_wordcount(av[1], ' '), tab, &head_a)
		|| (ac != 2 && !ft_already_sort(&head_a))
		|| ft_double(&head_a))
	{
		write (2, "Error\n", 6);
		if (tab)
			ft_clear_tab(tab);
		return (0);
	}
	//ft_clear_tab(tab);
	ft_dispatch(&head_a, &head_b, &head_op);
	ft_print_result(&head_op);
	ft_lstclear_modif(&head_a);
	ft_lstclear_modif_operation(&head_op);
	return (0);
}
*/