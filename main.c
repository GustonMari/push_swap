/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:02:36 by gmary             #+#    #+#             */
/*   Updated: 2021/12/21 16:36:30 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// check fuite de memoire lorsquon depasse le int min max !!!!
// a voir pour la mediane lorsquon a une suite impair que faire ??
int	main(int ac, char **av)
{
	t_list	*head_a = NULL;
	t_list	*head_b = NULL;
	t_list	*temp;
	//int mid;

	//mid = 0;
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
	ft_resolve_a(&head_a, &head_b);
	//finir resolve b, voir comment faire pour trie par chunk
	ft_resolve_b(&head_a, &head_b);
	printf("liste a\n");
	temp =head_a;
	//ft_rra(&head_a);
	while (head_a)
	{
		printf("%d\n", (head_a->content));
		head_a = head_a->next;
	}
	printf("liste b\n");
	while (head_b)
	{
		printf("%d\n", (head_b->content));
		head_b = head_b->next;
	}
	ft_lstclear_modif(&head_a);
	return (0);
}
