/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:15:00 by gmary             #+#    #+#             */
/*   Updated: 2021/12/30 08:09:51 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check(char **av)
{
	if (!ft_check_num(av))
		return (0);
	if (!ft_check_double(av))
		return (0);
	return (1);
}

int	ft_check_limits(long long nb)
{
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	else
		return (1);
}

int	ft_check_double(char **av)
{
	int	j;
	int	k;

	j = 1;
	k = 2;
	while(av[j])
	{
		k = j + 1;
		while(av[k])
		{
			if (!ft_strcmp(av[j], av[k]))
				return (0);
			k++;
		}
		j++;
	}
	return (1);
}

int	ft_check_num(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while(av[j])
	{
		i = 0;
		while(av[j][i])
		{
			if (av[j][i] != '-' && !ft_isdigit(av[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_already_sort(t_list **head)
{
	t_list	*max;
	t_list	*min;

	max = *head;
	min = *head;
	max = max->next;
	while (max)
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
