/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:40:45 by gmary             #+#    #+#             */
/*   Updated: 2022/01/06 09:08:34 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//a tej stdio.h
#include <stdio.h>

int	ft_med(int *tab, int size)
{
	//if (size % 2 == 0)
	//	return (0);
	//else
	//if (size % 2 == 0)
		return (tab[size / 2]);
	//else
	//	return (tab[(size + 1) / 2]);
}

int	ft_med_position(t_list *head, int count)
{
	//int	size;
	int	*tab;
	int	i;
	int	mid;

	i =0;
	//size = ft_lstsize(*head);
	tab = malloc(sizeof(int) * count);
	if (!tab)
		return (0);
	while (i < count)
	{
		tab[i] = (head)->content;
		(head) = (head)->next;
		i++;
	}
	// faire quick sort
	ft_quick_sort(tab, 0, count -1);
	i = 0;
	mid = ft_med(tab, count);
	free(tab);
	return (mid);
}

int	ft_med_position_chunk(t_list **head, int chunk)
{
	int	size;
	int	*tab;
	int	i;
	int	mid;
	t_list	*temp = NULL;

	temp = *head;
	i =0;
	//size = ft_lstsize(*head);
	size = ft_chunk_size(temp, chunk);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	temp = *head;
	while (i < size)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	ft_quick_sort(tab, 0, size -1);
	i = 0;
	mid = ft_med(tab, size);
	free(tab);
	return (mid);
}

// a check apres
void	ft_swap_tab(int *tab, int a, int b)
{
	int	temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

int	ft_partition(int *tab, int begin, int end)
{
	int	i;
	int	j;
	int pivot;

	pivot = tab[end];
	i = begin - 1;
	j = begin;

	while (j < end)
	{
		//j++;
		if (tab[j] <= pivot)
		{
			i++;
			ft_swap_tab(tab, i, j);
		}
		j++;
	}
	ft_swap_tab(tab, i + 1, end);
	return (i + 1);
}

void	ft_quick_sort(int *tab, int begin, int end)
{
	int	nb;

	if (begin >= end)
		return ;
	nb = ft_partition(tab, begin, end);
	ft_quick_sort(tab, begin, nb - 1);
	ft_quick_sort(tab, nb + 1, end);

}