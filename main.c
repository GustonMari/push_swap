/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:02:36 by gmary             #+#    #+#             */
/*   Updated: 2021/12/16 13:49:34 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


/*
		-pb et pa ne marche pas lorsque leurs liste sont egal a 1 element 
		alors la liste est dupp
*/

// ATTENTION TEJ LE ITOA
int	main(int ac, char **av)
{

	t_list	*head;
	t_list	*temp;
	int		i;
	long 	nb;
	
	i =1;
	nb = 0;
	while (i < ac)
	{
		//tej itoa
		//on peut surement regler le pb de compilation, avec une variable temp
		//pq zero pb avec des char ??
		nb = atoi(av[i]);
		ft_lstadd_back(&head, ft_lstnew(nb));
		i++;
	}
	printf (ft_med(head));
	temp = head;
	while (temp)
	{
		printf("%d\n", (int)temp->content);
		temp = temp->next;
	}
	//printf("liste b\n");
	//temp = head2;
	//while (temp)
	//{
	//	printf("%s\n", (char *)temp->content);
	//	temp = temp->next;
	//}
	return (0);
}

/*
int	main(void)
{
	t_list	*head;
	t_list	*new1;
	t_list	*new2;
	t_list	*new3;
	t_list	*new4;
	t_list	*new5;
	t_list	*temp;
	
	head = ft_lstnew("0");
	new1 = ft_lstnew("1");
	new2 = ft_lstnew("2");
	new3 = ft_lstnew("3");
	new4 = ft_lstnew("4");
	new5 = ft_lstnew("5");
	ft_lstadd_back(&head, new1);
	ft_lstadd_back(&head, new2);
	ft_lstadd_back(&head, new3);
	ft_lstadd_back(&head, new4);
	ft_lstadd_back(&head, new5);

	t_list	*head2;
	//t_list	*new1;
	//t_list	*new2;
	//t_list	*new3;
	//t_list	*new4;
	//t_list	*new5;
	//t_list	*temp;
	
	head2 = ft_lstnew("10");
	//ft_lstadd_back(&head2, ft_lstnew("11"));
	//ft_lstadd_back(&head2, ft_lstnew("12"));
	//ft_lstadd_back(&head2, ft_lstnew("13"));
	//ft_lstadd_back(&head2, ft_lstnew("14"));
	//ft_lstadd_back(&head2, ft_lstnew("15"));
	//printf("before swap\n");
	//temp = head;
	//while (temp)
	//{
	//	printf("%s\n", (char *)temp->content);
	//	temp = temp->next;
	//}
	ft_pa(&head, &head2);
	printf("liste a\n");
	temp = head;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	printf("liste b\n");
	temp = head2;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
}
*/

/*
	1) trouver le plus petit element et lassigner en tant que pivot
	2) Rearangement
	-si un element est plus grand que le pivot on y place un pointeur temp
	-des que lon tombe sur un chiffre inferrieur au pivot on swap lelement et le pointeur temp 
	=> pour optimiser le temps de triage on peut definir une valeur max que l'on redefini a chaque passage
	-apres un swap on repars du debut de la list
	- on sarrete lorsquon arrive a l'avant dernier element et l'on swap temp avec le pivot
	3) on replace le pivot sur l'extreme gauche et on repete letape 2
	
*/