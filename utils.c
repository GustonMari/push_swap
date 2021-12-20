/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:37:06 by gmary             #+#    #+#             */
/*   Updated: 2021/12/20 15:32:42 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

//void	ft_free(int nb)
//{
//	free(nb);
//}

int	ft_create_new(int ac, char **av, t_list **head)
{
	int		i;
	long	nb;
	
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (!ft_check_limits(nb))
		{
			ft_lstclear_modif(head);
			return (0);
		}
		ft_lstadd_back(head, ft_lstnew_modif((int)nb));
		i++;
	}
	return (1);
}

