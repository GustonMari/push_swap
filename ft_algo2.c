/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:56:44 by gmary             #+#    #+#             */
/*   Updated: 2022/01/07 10:57:12 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort(int *tab, int begin, int end)
{
	int	nb;

	if (begin >= end)
		return ;
	nb = ft_partition(tab, begin, end);
	ft_quick_sort(tab, begin, nb - 1);
	ft_quick_sort(tab, nb + 1, end);
}
