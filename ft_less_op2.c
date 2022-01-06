/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less_op2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:06:26 by gmary             #+#    #+#             */
/*   Updated: 2022/01/06 17:40:22 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
sa = 1, ra = 2, rra = 3, pb = 4,  sb = 5, rb = 6, rrb = 7, pa = 8, ss = 9, rr = 10, rrr = 11

	int        nb2;
    int        nb3;
    int        nb4;

    nb2 = (*lst)->next->content;
    nb3 = (*lst)->next->next->content;
    nb4 = (*lst)->next->next->next->content;
    if (nb2 == 2 && nb3 == 4 && nb4 == 3)
        return (0);
    else if (nb2 == 6 && nb3 == 8 && nb4 == 7)
        return (1);
    return (-1);

	en gros je transforme ra pb rra en sa pb
et pareil pour l'inverse (avec b)
*/