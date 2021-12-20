/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:57:39 by gmary             #+#    #+#             */
/*   Updated: 2021/12/20 10:03:29 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

/*
	 libft  && utils
*/
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int	ft_lstsize(t_list *lst);
int	ft_isdigit(int c);
t_list	*ft_lstnew_modif(int	content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
int	ft_med_position(t_list *head);
int ft_strcmp(char *s1, char *s2);
void	ft_create_new(int ac, char **av, t_list **head);
int	ft_atoi(const char *str);




/*
	mouvement function
*/
void	ft_sa(t_list **head);
void	ft_ra(t_list **head);
void	ft_rra(t_list **head);
void	ft_pa(t_list **head_a, t_list **head_b);
void	ft_pb(t_list **head_a, t_list **head_b);
void	ft_ss(t_list **head_a, t_list **head_b);
void	ft_rr(t_list **head_a, t_list **head_b);
void	ft_rrr(t_list **head_a, t_list **head_b);

/*
		check function
*/
int	ft_already_sort(t_list **head);
int	ft_check(char **av);
int	ft_check_num(char **av);
int	ft_check_double(char **av);




/*
		Sort function
*/
void	ft_sort_five(t_list **head_a, t_list **head_b);

#endif