/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:17:20 by marvin            #+#    #+#             */
/*   Updated: 2024/08/24 18:42:19 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	long 			content;
	struct s_list	*next;
}	t_list;


t_list	*ft_lstnew(long content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list *lst);
int		ft_strlen(char *s);
long	ft_atoi_simple(char *str, long *i);
t_list	*ft_get_arg_in_lst(char *str);
long	ft_abs(long nmb);
int		create_lst(t_list **lst, int nv, char **arg);
void	case_management(int nv, t_list	**lst_a, t_list	**lst_b);
void	ft_swap(t_list **lst);
void	ft_push_x_to_y(t_list **lst_x, t_list **lst_y);
void	ft_rotate(t_list **lst);
void	ft_reverse_rotate(t_list **lst);
int		int_check(int nv, char **arg);
int		ft_cmp_lst(int  content, t_list **lst, int i);
int		check_double(t_list  **lst);
int		check_max_min(t_list  **lst);
int		ft_in_cresent_order(t_list **lst);
int		ft_in_decresent_order(t_list **lst);
void	ft_rotate_b(int nub_a, t_list **lst);
void	ft_reverse_rotate_b(int nmb_a, t_list **lst);
long	define_sense_rotation(int nmb_a, t_list **lst);
long	define_sense_rotation_bis(t_list **lst);
void	ft_atlgorithm(t_list **lst_a, t_list **lst_b);
void	ft_rotate_two(int nmb_a, t_list **lst);
void	ft_rotate_a(t_list **lst_a, t_list **lst_b);
void	ft_rotate_three_in_a(t_list **lst);
void 	two_arguments(t_list **lst);
void 	three_arguments(t_list **lst);
long	case_a(t_list **lst_a, t_list **lst_b);
long	case_b(t_list **lst_a, t_list **lst_b);
long	case_c(t_list **lst_a, t_list **lst_b);
void	case_3_in_a(t_list **lst_a, t_list **lst_b);
long	case_general(t_list **lst_a, t_list **lst_b, long p);
long	ft_rotate_two_without_print(int nmb_a, t_list **lst, t_list **lst_c);
long	ft_rotate_b_without_print(int nmb_a, t_list **lst, t_list **lst_c);
long	ft_reverse_rotate_b_without_print(int nmb_a, t_list **lst, t_list **lst_c);
void	undo_instructions(t_list **lst_a, t_list **lst_b, t_list **lst_c);

void    PRINT_STACK(t_list  **lst);

#endif