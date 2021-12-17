/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:02:36 by gmary             #+#    #+#             */
/*   Updated: 2021/12/17 15:46:39 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


/*
		-pb et pa ne marche pas lorsque leurs liste sont egal a 1 element 
		alors la liste est dupp
*/

// ATTENTION TEJ LE ITOA
/*
int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*temp;
	int		i;
	int 	nb;
	int		*p;
	
	i =1;
	nb = 0;
	head = NULL;
	while (i < ac)
	{
		nb = atoi(av[i]);
		ft_lstadd_back(&head, ft_lstnew(nb));
		i++;
	}
	printf ("list sort = %d\n", ft_already_sort(&head));
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
*/

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
	new3 = ft_lstnew("8");
	new4 = ft_lstnew("4");
	new5 = ft_lstnew("5");
	ft_lstadd_back(&head, new1);
	ft_lstadd_back(&head, new2);
	ft_lstadd_back(&head, new3);
	ft_lstadd_back(&head, new4);
	ft_lstadd_back(&head, new5);

	printf ("list sort = %d\n", ft_already_sort(&head));
	t_list	*head2;
	//t_list	*new1;
	//t_list	*new2;
	//t_list	*new3;
	//t_list	*new4;
	//t_list	*new5;
	//t_list	*temp;
	
	//head2 = ft_lstnew("10");
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
	//head2 = NULL;
	ft_pb(&head, &head2);
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

int	main(void)
{
	t_list	*head_a;
	t_list	*head_b = NULL;
	t_list	*new;
	int a = 1;
	int b = 5;
	int c = 4;
	int d = 10;
	int	e = 8;
	void *p = &a;

	head_a = ft_lstnew(p);
	p = &b;
	new = ft_lstnew(p);
	ft_lstadd_back(&head_a, new);
	p = &c;
	new = ft_lstnew(p);
	ft_lstadd_back(&head_a, new);
	p = &d;
	new = ft_lstnew(p);
	ft_lstadd_back(&head_a, new);
	p = &e;
	new = ft_lstnew(p);
	ft_lstadd_back(&head_a, new);
	
	ft_sort_five(&head_a, &head_b);
	printf ("list sort = %d\n", ft_already_sort(&head_a));
	while (head_a)
	{
		printf(" %d\n ", *(int *)(head_a->content));
		head_a = head_a->next;
	}
	return (0);
}

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