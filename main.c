/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:02:36 by gmary             #+#    #+#             */
/*   Updated: 2021/12/20 10:11:57 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


/*
		-pb et pa ne marche pas lorsque leurs liste sont egal a 1 element 
		alors la liste est dupp
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

int	main(int ac, char **av)
{
	t_list	*head_a = NULL;
	
	if (ac == 1 || !ft_check(av))
	{
		write (2,"Error\n", 6);
		return (0);
	}
	ft_create_new(ac, av, &head_a);
	if (!ft_already_sort(&head_a))
	{
		write (2,"Error\n", 6);
		return (0);
	}
	while (head_a)
	{
		printf("%d\n", (head_a->content));
		head_a = head_a->next;
	}
	return (0);
}

void	ft_create_new(int ac, char **av, t_list **head)
{
	int	i;
	int	nb;
	
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		ft_lstadd_back(head, ft_lstnew_modif(nb));
		i++;
	}
}