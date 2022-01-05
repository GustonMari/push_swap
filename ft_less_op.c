/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 05:39:25 by gmary             #+#    #+#             */
/*   Updated: 2022/01/05 16:30:19 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_operation(char *s1, char *s2)
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

int	ft_compact(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	if ((!ft_strcmp(s1, "sa") && !ft_strcmp(s2, "sb")) ||
		(!ft_strcmp(s1, "sb") && !ft_strcmp(s2, "sa")))
		return (1);
	if ((!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rb")) ||
		(!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "ra")))
		return (1);
	if ((!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "rrb")) ||
		(!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rra")))
		return (1);
	return (0);
}

void	ft_del_two_op(t_operation **head_op)
{
	t_operation *first;
	t_operation *second;

	first = (*head_op)->next;
	second = (*head_op)->next->next;
	(*head_op)->next = (*head_op)->next->next->next;
	free(first);
	free(second);
}
void	ft_del_two_op_and_add(t_operation **head_op)
{
	t_operation	*first;
	t_operation	*second;
	t_operation	*new;
	t_operation	*temp;

	first = (*head_op)->next;
	second = (*head_op)->next->next;
	if (!first || !second)
		return ;
	if ((!ft_strcmp(first->operation, "sa") && !ft_strcmp(second->operation, "sb")) ||
		(!ft_strcmp(first->operation, "sb") && !ft_strcmp(second->operation, "sa")))
		new = ft_create_new_operation("ss");
	if ((!ft_strcmp(first->operation, "ra") && !ft_strcmp(second->operation, "rb")) ||
		(!ft_strcmp(first->operation, "rb") && !ft_strcmp(second->operation, "ra")))
		new = ft_create_new_operation("rr");
	if ((!ft_strcmp(first->operation, "rra") && !ft_strcmp(second->operation, "rrb")) ||
		(!ft_strcmp(first->operation, "rrb") && !ft_strcmp(second->operation, "rra")))
		new = ft_create_new_operation("rrr");
	temp = (*head_op)->next->next->next;
	(*head_op)->next = new;
	new->next = temp;
	free(first);
	free(second);
}

void	ft_first_epuration(t_operation **head_op)
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
		next_elem = (*head_op)->next;
		if (ft_compact(next_elem->operation, next_elem->next->operation))
			ft_del_two_op_and_add(head_op);
		(*head_op) = (*head_op)->next;
	}
	*head_op = begin;
}