/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:46:10 by gmary             #+#    #+#             */
/*   Updated: 2022/01/05 10:45:53 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operation	*ft_create_new_operation(char *ope)
{
	t_operation	*new;

	new = malloc(sizeof(t_operation));
	if (!new)
		return (NULL);
	new->operation = ope;
	new->next = NULL;
	return (new);
}

void	ft_addback_operation(t_operation **alst, t_operation *new)
{
	t_operation	*temp;

	if (!*alst)
	{
		//new->prev = NULL;
		*alst = new;
		return ;
	}
	temp = *alst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	//new->prev = temp;
}
