/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:40:45 by gmary             #+#    #+#             */
/*   Updated: 2021/12/17 14:09:48 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//a tej stdio.h
#include <stdio.h>
//ft pour mediane a finir
int	ft_med_position(t_list *head)
{
	int	size;
	
	size = ft_lstsize(head);
	return ((size + 1)/2);
}

void	ft_div_med(t_list **head_a, t_list **head_b)
{
	
}


int	ft_already_sort(t_list **head)
{
	//int		ok;
	t_list	*max;
	t_list	*min;

	max = *head;
	min = *head;
	//ok = 0;
	max = max->next;
	while (max)
	{
		if (*(int *)min->content > *(int *)max->content)
		{	
			return (0);
			//ok++;
			//printf("ok %d\n", ok);
		}
		min = min->next;
		max = max->next;
	}
	//if (*(int *)min->content > *(int *)max->content)
	//{	
	//	return (0);
	//	//ok++;
	//	//printf("ok %d\n", ok);
	//}
	//printf("size %d\n", ft_lstsize(*head));
	//if (ft_lstsize(*head) == ok)
	//	return (1);
	return (1);
}