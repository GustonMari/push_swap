/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:56:49 by gmary             #+#    #+#             */
/*   Updated: 2022/01/07 11:02:29 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_not_sort(t_list *head, int mid, int count)
{
	while (count && head)
	{
		--count;
		if (head->content <= mid)
			return (1);
		head = head->next;
	}
	return (0);
}

int	ft_chunk_not_sort_reverse(t_list *head, int mid, int count)
{
	while (count && head)
	{
		--count;
		if (head->content >= mid)
			return (1);
		head = head->next;
	}
	return (0);
}

int	ft_already_sort_chunk(t_list **head, int chunk)
{
	t_list	*max;
	t_list	*min;

	max = *head;
	min = *head;
	max = max->next;
	while (max && max->chunk_index != chunk)
	{
		min = min->next;
		max = max->next;
	}
	while (max && max->chunk_index == chunk)
	{
		if (min->content > max->content)
		{	
			return (1);
		}
		min = min->next;
		max = max->next;
	}
	return (0);
}

int	ft_double(t_list **head)
{
	t_list	*temp;
	t_list	*duble;

	temp = *head;
	while (temp)
	{
		duble = temp->next;
		while (duble)
		{
			if (duble->content == temp->content)
				return (1);
			duble = duble->next;
		}
		temp = temp->next;
	}
	return (0);
}
