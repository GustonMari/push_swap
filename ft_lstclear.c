/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:33:16 by gmary             #+#    #+#             */
/*   Updated: 2021/12/22 16:52:38 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_modif(t_list **lst)
{
	t_list	*temp;

	while ((*lst))
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		temp->content = 0;
		temp->chunk_index = 0;
		free(temp);
	}
}
