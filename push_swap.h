/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:17:20 by marvin            #+#    #+#             */
/*   Updated: 2024/09/04 17:56:21 by ele-borg         ###   ########.fr       */
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
	long			content;
	struct s_list	*next;
}	t_list;

typedef struct s_elements
{
	t_list	**lst_a;
	t_list	**lst_b;
	t_list	**lst_c;
	long	r;
	long	sense_a;
	long	sense_b;
	long	*p;
	long	val;
	long	*nmb;
}	t_elements;

t_list	*ft_lstnew(long content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list *lst);

int		ft_strlen(char *s);
long	ft_atoi_simple(char *str, long *i);
long	ft_abs(long nmb);
int		ft_in_cresent_order(t_list **lst);
int		ft_in_decresent_order(t_list **lst);

void	ft_swap(t_list **lst);
void	ft_push_x_to_y(t_list **lst_x, t_list **lst_y);
void	ft_rotate(t_list **lst);
void	ft_reverse_rotate(t_list **lst);

int		ft_check_segment(int nv, char **arg, int i);
int		ft_int_check(int nv, char **arg);
int		ft_cmp_lst(int content, t_list **lst, int i);
int		ft_check_double(t_list **lst);
int		ft_check_max_min(t_list **lst);

t_list	*ft_get_arg_in_lst(char *str, int *j);
int		ft_create_lst(t_list **lst, int nv, char **arg);
int		ft_case_management(int nv, t_list	**lst_a, t_list	**lst_b);

void	ft_two_arguments(t_list **lst);
void	ft_instructions(long i, t_list **lst);
void	ft_three_arguments(t_list **lst);
int		ft_find_min_index(t_list *lst);
void	ft_four_arguments(t_list **lst_a, t_list **lst_b);

void	ft_return_median(t_list **lst, long	*median);
long	ft_position_little(t_list **lst_a, long median);
void	ft_put_to_b(t_list **lst_a, long median);
void	ft_two_arguments_reverse(t_list **lst);
void	ft_five_arguments(t_list **lst_a, t_list **lst_b);

long	ft_define_sense_rotation_a(t_list **lst, long p);
long	ft_define_sense_rotation_b(int nmb_a, t_list **lst);
long	ft_define_sense_rotation(t_list **lst);
long	ft_end_rot(long nmb_a, t_list **lst);

void	ft_rotation_a(t_list **lst_a, long p_a);
void	ft_rotation_b(t_list **lst, long nmb_a);
void	ft_b_rotation_and_push_to_a(t_list **lst_a, t_list **lst_b);
int		ft_atlgorithm(t_list **lst_a, t_list **lst_b);

void	ft_undo_instr(t_list **lst_a, t_list **lst_b, t_list **lst_c);
int		ft_put_in_lst_c(t_list **lst_c, long n);
void	ft_value_2_push(t_list **lst_a, t_list **lst_b, long *pmin, long *vmin);

int		ft_nmb_rab(t_list **lst_a, t_list **lst_b, t_list **lst_c, long *p);
int		ft_nmb_rrab(t_list **lst_a, t_list **lst_b, t_list **lst_c, long *p);
int		ft_nmb_rotation_a(t_list **lst_a, t_list **lst_c, long *p, long *nmb);
int		ft_nbm_rotation_b(t_list **lst_b, t_list **lst_c, long *nb, long sense);
void	ft_instructions_nmb(t_list **lst_a, t_list **lst_b, long p, long *nmb);

void	ft_clear(t_list **lst_a, t_list **lst_b, t_list **lst_c);
long	ft_value_a(t_list **lst_a, long p);
void	ft_simultaneous_actions(t_elements *elm);
void	ft_actions(t_elements *elm);

void	print_stack(t_list **lst);

#endif