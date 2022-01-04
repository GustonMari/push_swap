/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:57:39 by gmary             #+#    #+#             */
/*   Updated: 2022/01/04 14:54:50 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int				content;
	int				chunk_index;
	struct s_list	*next;
	//struct s_list	*prev;
}				t_list;

typedef struct d_list
{
	int	size;
	struct s_list *first;
	struct s_list *last;
}				D_list;

/*
	 libft  && utils
*/
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear_modif(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int	ft_lstsize(t_list *lst);
int	ft_isdigit(int c);
t_list	*ft_lstnew_modif(int	content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
int ft_strcmp(char *s1, char *s2);
int	ft_create_new(int ac, char **av, t_list **head);
long long	ft_atoi(const char *str);
void	ft_free(int nb);


/*
	mouvement function
*/
void	ft_sa(t_list **head);
void	ft_sb(t_list **head);
void	ft_rb(t_list **head);
void	ft_ra(t_list **head);
void	ft_rrb(t_list **head);
void	ft_rra(t_list **head);
void	ft_pa(t_list **head_a, t_list **head_b, int chunk);
void	ft_pb(t_list **head_a, t_list **head_b, int chunk);
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
int	ft_check_limits(long long nb);
//peut etre a tej a voir
int	ft_chunk_not_sort(t_list *head, int mid, int count);
int	ft_chunk_not_sort_reverse(t_list *head, int mid, int count);


/*
		Sort function
*/
void	ft_sort_five(t_list **head_a, t_list **head_b);
int	ft_med_position(t_list *head, int count);
int	ft_med_position_chunk(t_list **head, int chunk);
void	ft_swap_tab(int *tab, int a, int b);
void	ft_quick_sort(int *tab, int begin, int end);
void ft_resolve_a(t_list **stack_a, t_list **stack_b, int count);
void ft_resolve_b(t_list **stack_a, t_list **stack_b, int count);
//void	ft_resolve_a(t_list	**head_a, t_list **head_b, int chunk);
//void	ft_resolve_b(t_list	**head_a, t_list **head_b, int chunk);
int ft_all_below_mid(t_list *head, int mid, int chunk);
int	ft_check_chunk_max(t_list *head);
int	ft_chunk_size(t_list *lst, int chunk);
void	ft_solve_two(t_list **head);
void	ft_solve_three(t_list **head);
void	ft_solve_three_reverse(t_list **head);
void	ft_solve_two_reverse(t_list **head);
void ft_resolve_case(t_list **head, int chunk);
void ft_resolve_case_reverse(t_list **head, int chunk);
int ft_all_above_mid(t_list *head, int mid, int chunk);
int	ft_resolve_connect(t_list **head_a, t_list **head_b, int chunk);
int	ft_already_sort_chunk(t_list **head, int chunk);
// voir si tej ce block en dessous
void	ft_special_case_reverse(t_list **head, int chunk);
void	ft_solve_three_reverse_begin(t_list	**head);
void	ft_solve_three_begin(t_list	**head);


#endif