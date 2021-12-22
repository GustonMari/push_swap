/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:05:32 by gmary             #+#    #+#             */
/*   Updated: 2021/12/22 10:17:48 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_size(t_list *lst, int chunk)
{
	int	i;

	i = 0;
	while (lst)
	{	
		if (lst->chunk_index != chunk)
			lst = lst->next;
		if (lst && lst->chunk_index == chunk)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}
