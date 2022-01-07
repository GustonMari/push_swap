/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:02:36 by gmary             #+#    #+#             */
/*   Updated: 2022/01/07 10:38:35 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dispatch(t_list **head_a, t_list **head_b, t_operation **head_op)
{
	
}

int	main(int ac, char **av)
{
	t_list		*head_a = NULL;
	t_list		*head_b = NULL;
	t_operation	*head_op = NULL;
	t_list		*temp1;
	t_operation	*temp3;

	if (ac == 1 || !ft_check(av))
	{
		write (2,"Error\n", 6);
		return (0);
	}
	if (!ft_create_new(ac, av, &head_a)
		|| (ac != 2 && !ft_already_sort(&head_a))
		|| ft_double(&head_a))
	{
		write (2,"Error\n", 6);
		return (0);
	}
	if (ft_lstsize(head_a) == 2)
		ft_solve_two(&head_a, &head_op);
	else if (ft_lstsize(head_a) == 3)
		ft_solve_three(&head_a, &head_op);
	else
		ft_resolve_a(&head_a, &head_b, ft_lstsize(head_a), &head_op);
	temp1 = head_a;
	temp3 = head_op;
	ft_first_epuration(&temp3);
	ft_second_epuration(&temp3);
	ft_print_result(&head_op);
	ft_lstclear_modif(&temp1);
	ft_lstclear_modif_operation(&temp3);
	return (0);
}

/*
int	main(int ac, char **av)
{
	t_list		*head_a = NULL;
	t_list		*head_b = NULL;
	t_operation	*head_op = NULL;
	t_list		*temp1;
	//t_list	*temp2;
	t_operation	*temp3;

	if (ac == 1 || !ft_check(av))
	{
		write (2,"Error\n", 6);
		return (0);
	}
	if (!ft_create_new(ac, av, &head_a) || (ac != 2 && !ft_already_sort(&head_a)))
	{
		write (2,"Error\n", 6);
		return (0);
	}
	//ft_solve_three(&head_a);
	//ft_solve_three_reverse(&head_a);
	//while (ft_already_sort(&head_a))
	//{
	// ATTENTION BIEN FAIRE FONCTION POUR 5 ELEMENTS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (ft_lstsize(head_a) == 2)
		ft_solve_two(&head_a, &head_op);
	else if (ft_lstsize(head_a) == 3)
		ft_solve_three(&head_a, &head_op);
	else
		ft_resolve_a(&head_a, &head_b, ft_lstsize(head_a), &head_op);
	temp1 = head_a;
	////temp2 = head_b;
	temp3 = head_op;
	//printf("liste a\n");
	//while (head_a)
	//{
	//	printf("%d | %d\n", (head_a->content), head_a->chunk_index);
	//	head_a = head_a->next;
	//}
	ft_first_epuration(&temp3);
	ft_print_result(&head_op);
	//while (head_op)
	//{
	//	printf("%s\n", (head_op->operation));
	//	head_op = head_op->next;
	//}
	ft_lstclear_modif(&temp1);
	ft_lstclear_modif_operation(&temp3);
	//ft_lstclear_modif(&temp2);
	return (0);
}
*/