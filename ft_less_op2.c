/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less_op2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:06:26 by gmary             #+#    #+#             */
/*   Updated: 2022/01/07 11:20:07 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ptr(t_operation **h_o, t_operation *n1, t_operation *n2, t_operation *o)
{
	t_operation	*temp;
	int			i;

	i = 0;
	temp = (*h_o)->next->next->next->next;
	(*h_o)->next = n1;
	n1->next = n2;
	n2->next = temp;
	while (i < 3)
	{
		temp = o->next;
		free(o);
		o = temp;
		i++;
	}
}

void	ft_del_three_add_two(t_operation **head_op)
{
	t_operation	*op1;
	t_operation	*new1;
	t_operation	*new2;

	new1 = NULL;
	new2 = NULL;
	op1 = (*head_op)->next;
	if (!op1 || !(op1->next) || !(op1->next->next))
		return ;
	if (!ft_strcmp((op1->operation), "ra"))
	{
		new1 = ft_create_new_operation("sa");
		new2 = ft_create_new_operation("pb");
	}
	if (!ft_strcmp((op1->operation), "rb"))
	{
		new1 = ft_create_new_operation("sb");
		new2 = ft_create_new_operation("pa");
	}
	ptr(head_op, new1, new2, op1);
}

int	ft_com(char *s1, char *s2, char *s3)
{
	if (!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "pb") && !ft_strcmp(s3, "rra"))
		return (1);
	if (!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "pa") && !ft_strcmp(s3, "rrb"))
		return (1);
	return (0);
}

void	ft_second_epuration(t_operation **head_op)
{
	t_operation	*n;
	t_operation	*begin;

	begin = *head_op;
	while (*head_op)
	{
		n = (*head_op)->next;
		if (!n || !n->next || !n->next->next)
			break ;
		if (ft_com(n->operation, n->next->operation, n->next->next->operation))
			ft_del_three_add_two(head_op);
		(*head_op) = (*head_op)->next;
	}
	*head_op = begin;
}
/*
    nb2 = (*lst)->next->content;
    nb3 = (*lst)->next->next->content;
    nb4 = (*lst)->next->next->next->content;
    if (nb2 == "ra" && nb3 == "pb" && nb4 == "rra")
        ft_del_3_add_sa_pb
    else if (nb2 == "rb" && nb3 == "pa" && nb4 == "rrb")
		ft_del_3_add_sb_pa
        return (1);
    return (-1);

	en gros je transforme ra pb rra en sa pb
et pareil pour l'inverse (avec b)
*/
