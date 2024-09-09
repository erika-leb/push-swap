/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:18:04 by ele-borg          #+#    #+#             */
/*   Updated: 2024/09/04 17:56:47 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "push_swap.h"

t_list	*ft_get_arg_in_lst(char *str, int *j);
int		ft_create_lst(t_list **lst, int nv, char **arg);

void	ft_checker(t_list **lst_a, t_list **lst_b);
void	ft_apply_instruction_a(char *line, t_list **lst_a, t_list **lst_b);
void	ft_apply_instruction_b(char *line, t_list **lst_a, t_list **lst_b);
void	ft_check_in_order(t_list **lst_a, t_list **lst_b);
int		ft_strcmp(char *s1, char *s2);
int		is_instructions(char *line, t_list **lst_a, t_list **lst_b, int t);
int		is_instructions_bis(char *line, t_list **lst_a, t_list **lst_b, int t);
void	ft_check_void(t_list **lst_a, t_list **lst_b);

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

int		ft_int_check(int nv, char **arg);
int		ft_cmp_lst(int content, t_list **lst, int i);
int		ft_check_double(t_list **lst);
int		ft_check_max_min(t_list **lst);

#endif