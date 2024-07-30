/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:17:20 by marvin            #+#    #+#             */
/*   Updated: 2024/07/24 09:17:20 by marvin           ###   ########.fr       */
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
    int             content;
    struct s_list   *next;
}               t_list;

t_list  *ft_lstnew(int content);
void    ft_lstadd_front(t_list **lst, t_list *new);
int     ft_lstsize(t_list **lst);
t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstclear(t_list *lst);
int     ft_strlen(char *s);
int     ft_atoi_simple(char *str);
void    ft_swap(t_list **lst);
void    ft_push_x_to_y(t_list **lst_x, t_list **lst_y);
void    ft_rotate(t_list **lst);
int     int_check(int nv, char **arg);
int     ft_cmp_lst(int  content, t_list **lst, int i);
int     check_double(t_list  **lst);
int     check_max_min(t_list  **lst);
int     ft_in_cresent_order(t_list **lst);
int     ft_in_decresent_order(t_list **lst);
void    ft_rotate_b(int nub_a, t_list **lst);
void    ft_atlgorithm(t_list **lst_a, t_list **lst_b);

void    PRINT_STACK(t_list  **lst, int nv);

#endif