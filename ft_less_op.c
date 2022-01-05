/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 05:39:25 by gmary             #+#    #+#             */
/*   Updated: 2022/01/05 15:26:45 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_operation(char *s1, char *s2)
{
	if (!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rra"))
		return (1);
	if (!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "ra"))
		return (1);
	if (!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "rrb"))
		return (1);
	if (!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rb"))
		return (1);
	if (!ft_strcmp(s1, "sa") && !ft_strcmp(s2, "sa"))
		return (1);
	if (!ft_strcmp(s1, "sb") && !ft_strcmp(s2, "sb"))
		return (1);
	if (!ft_strcmp(s1, "pa") && !ft_strcmp(s2, "pb"))
		return (1);
	if (!ft_strcmp(s1, "pb") && !ft_strcmp(s2, "pa"))
		return (1);
	return (0);
}

void ft_del_two_op(t_operation **head_op)
{
	t_operation *first;
	t_operation *second;

	first = (*head_op)->next;
	second = (*head_op)->next->next;
	(*head_op)->next = (*head_op)->next->next->next;
	free(first);
	free(second);
}

void ft_first_epuration(t_operation **head_op)
{
	t_operation *next_elem;
	t_operation	*begin;

	begin = *head_op;
	while (*head_op)
	{
		next_elem = (*head_op)->next;
		if (next_elem == NULL || next_elem->next == NULL)
			break ;
		if (ft_is_operation(next_elem->operation, next_elem->next->operation))
			ft_del_two_op(head_op);
		//if (ft_compact(*head_op)->operation, (*head_op)->next->operation))
		//	ft_del_two_op_and_add(*head_op);
		(*head_op) = (*head_op)->next;
	}
	*head_op = begin;
}