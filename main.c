/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:02:36 by gmary             #+#    #+#             */
/*   Updated: 2022/01/04 14:47:42 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// check fuite de memoire lorsquon depasse le int min max !!!!
// a voir pour la mediane lorsquon a une suite impair que faire ??

//2 3 5 12 10 6 9 7 4 1 8 11 
// ./a.out 216 709 746 594 273 18 596 720 942 915 262 151

// ATTENTION BIEN TEST LE CAS OU 1 SEUL NB
//ATTENTION LORSQUON MARQUE 02 et 2 aucune erreur n'est declare


// modifie ft_resolve_a pour quelle choppe les chunks
int	main(int ac, char **av)
{
	t_list	*head_a = NULL;
	t_list	*head_b = NULL;
	t_list	*temp1;
	//t_list	*temp2;

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
		ft_solve_two(&head_a);
	else if (ft_lstsize(head_a) == 3)
		ft_solve_three(&head_a);
	else
		ft_resolve_a(&head_a, &head_b, ft_lstsize(head_a));
	temp1 = head_a;
	//temp2 = head_b;
	printf("liste a\n");
	while (head_a)
	{
		printf("%d | %d\n", (head_a->content), head_a->chunk_index);
		head_a = head_a->next;
	}
	//printf("liste b\n");
	//while (head_b)
	//{
	//	printf("%d | %d\n", (head_b->content), head_b->chunk_index);
	//	head_b = head_b->next;
	//}
	ft_lstclear_modif(&temp1);
	//ft_lstclear_modif(&temp2);
	return (0);
}
