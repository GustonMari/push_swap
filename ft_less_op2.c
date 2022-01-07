/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less_op2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:06:26 by gmary             #+#    #+#             */
/*   Updated: 2022/01/07 10:22:12 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del_three_add_two(t_operation **head_op)
{
	t_operation	*op1;
	t_operation	*new1 = NULL;
	t_operation	*new2 = NULL;
	t_operation	*temp;
	int			i;

	i = 0;
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
	temp = (*head_op)->next->next->next->next;
	(*head_op)->next = new1;
	new1->next = new2;
	new2->next = temp;
	while (i < 3)
	{
		temp = op1->next;
		free(op1);
		op1 = temp;
		i++;
	}
}

int	ft_compact_2(char *s1, char *s2, char *s3)
{
	if (!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "pb") && !ft_strcmp(s3, "rra"))
		return (1);
	if (!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "pa") && !ft_strcmp(s3, "rrb"))
		return (1);
	return (0);
}

void	ft_second_epuration(t_operation **head_op)
{
	t_operation	*n_elem;
	t_operation	*begin;

	begin = *head_op;
	while (*head_op)
	{
		n_elem = (*head_op)->next;
		if (!n_elem || !n_elem->next || !n_elem->next->next)
			break ;
		if (ft_compact_2(n_elem->operation, n_elem->next->operation, n_elem->next->next->operation))
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
