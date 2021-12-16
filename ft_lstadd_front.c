/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:44:15 by gmary             #+#    #+#             */
/*   Updated: 2021/12/16 07:01:15 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst)
	{
		*alst = new;
		return ;
	}
	else
	{
		new->next = *alst;
		*alst = new;
	}
}
