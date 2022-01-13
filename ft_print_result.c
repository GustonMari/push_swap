/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:46:55 by gmary             #+#    #+#             */
/*   Updated: 2022/01/13 09:20:05 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_result(t_operation **head_op)
{
	t_operation	*temp;
	
	while (*head_op)
	{
		temp = *head_op;
		ft_putstr((temp)->operation);
		write(1, "\n", 1);
		*head_op = (*head_op)->next;
		free(temp);
	}
}

/*
void	ft_print_result(t_operation **head_op)
{
	t_operation	*temp;
	
	while (*head_op)
	{
		temp = *head_op;
		ft_putstr((*head_op)->operation);
		write(1, "\n", 1);
		*head_op = (*head_op)->next;
	}
}
*/
