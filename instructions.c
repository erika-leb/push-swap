/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:50:19 by marvin            #+#    #+#             */
/*   Updated: 2024/07/27 10:50:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_list **lst)
{
    t_list  *temp;
    t_list  *current;

    if (*lst == NULL)
        return ;
    temp = *lst;
    *lst = (*lst) -> next;
    temp -> next = (*lst) -> next;
    (*lst) -> next = temp; 
}

void    ft_push_x_to_y(t_list **lst_x, t_list **lst_y)
{
    t_list  *temp;

    if (*lst_x == NULL)
        return ;
    temp = *lst_x;
    *lst_x = (*lst_x) -> next;
    temp -> next = *lst_y;
    *lst_y = temp; 
}

void    ft_rotate(t_list **lst)
{
    t_list  *temp;
    t_list  *current;

    if (*lst == NULL || (*lst) -> next == NULL)
        return ;
    temp = *lst;
    (*lst) = (*lst) -> next;
    temp -> next = NULL;
    current = *lst;
    while (current -> next != NULL)
        current = current -> next;
    current -> next = temp;
}

void    ft_reverse_rotate(t_list **lst)
{
    t_list  *current;
    t_list  *prec;
    t_list  *temp;

    if (*lst == NULL || (*lst) -> next == NULL)
        return ;
    current = *lst;
    while (current -> next != NULL)
    {
        prec = current;
        current = current -> next;
    }
    temp = current;
    prec -> next = NULL;
    current = *lst;
    temp -> next = current;
    *lst = temp;
}