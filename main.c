/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:02:36 by gmary             #+#    #+#             */
/*   Updated: 2021/12/20 17:37:39 by gmary            ###   ########.fr       */
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
	int mid;

	mid = 0;
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
	temp = head_a;
	mid = ft_med_position(&temp);
	free(temp);
	while (head_a->next)
	{
		//printf("%d\n", (head_a->content));
		head_a = head_a->next;
	}
	while (head_a)
	{
		printf("%d\n", (head_a->content));
		head_a = head_a->prev;
	}
	ft_lstclear_modif(&head_a);
	return (0);
}
