/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:40:45 by gmary             #+#    #+#             */
/*   Updated: 2021/12/20 09:15:57 by gmary            ###   ########.fr       */
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


