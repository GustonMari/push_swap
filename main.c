/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:02:36 by gmary             #+#    #+#             */
/*   Updated: 2021/12/22 13:26:04 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// check fuite de memoire lorsquon depasse le int min max !!!!
// a voir pour la mediane lorsquon a une suite impair que faire ??

//2 3 5 12 10 6 9 7 4 1 8 11 

// ATTENTION BIEN TEST LE CAS OU 1 SEUL NB


int	main(int ac, char **av)
{
	t_list	*head_a = NULL;
	t_list	*head_b = NULL;

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
	//pour fuite de memoire
	//temp = head_a;
	//mid = ft_med_position(&temp);
	//free(temp);
	
	ft_resolve_a(&head_a, &head_b, 0);
	ft_solve_two(head_a);
	ft_resolve_b(&head_a, &head_b, ft_check_chunk_max(head_b));
	printf("liste a\n");
	while (head_a)
	{
		printf("%d | %d\n", (head_a->content), head_a->chunk_index);
		head_a = head_a->next;
	}
	pritnf("mid point chunk 1=%d\n", ft_med_position(head_b));
	printf("liste b\n");
	while (head_b)
	{
		printf("%d | %d\n", (head_b->content), head_b->chunk_index);
		head_b = head_b->next;
	}
	ft_lstclear_modif(&head_a);
	return (0);
}
