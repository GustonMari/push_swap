/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:01:01 by gmary             #+#    #+#             */
/*   Updated: 2021/12/20 16:09:13 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_resolve_a(t_list	**head_a, t_list **head_b)
{
	int	mid;

	// surement passer par une valeur temp pour leak avec med_position
	mid = ft_med_position(head_a);
	// je pense que ma condition n'est pas bonne pour la boucle je devrais plustpot avoir un if pour stopper un recursion
	while (ft_already_sort(head_a))
	{
		while ((*head_a)->content < mid)
			ft_pb(head_a, head_b);
		whi
	}
}