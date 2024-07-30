/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:32:21 by marvin            #+#    #+#             */
/*   Updated: 2024/07/24 09:32:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_lstnew(int content)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    if (new == NULL)
        return (NULL);
    new -> content = content;
    new ->  next = NULL;
    return (new);
}

void    ft_lstadd_front(t_list **lst, t_list *new)
{
    new -> next = *lst;
    *lst = new;
}

int     ft_lstsize(t_list **lst)
{
    int     s;
    t_list  *current; 

    s = 0;
    current = *lst;
    if (*lst == NULL)
        return (0);
    while (current != NULL) 
    {
        s++;
        current = current -> next;
    }
    return (s);
}

t_list  *ft_lstlast(t_list *lst)
{
    t_list  *current;

    if (lst == NULL)
        return (NULL);
    current = lst;
    while (current -> next != NULL)
        current = current -> next;
    return (current);
}

void   ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *current;

    if (!new)
        return ;
    if (!lst)
    {
        *lst = new;
        return ;
    }
    current = *lst;
    while (current -> next != NULL)
        current = current -> next;
    current -> next = new;
}

void    ft_lstclear(t_list *lst)
{   
    t_list  *current;
    while (lst != NULL)
    {
        //(*lst) -> content = (int) NULL;
        current = (lst) -> next;
        free(lst);
        lst = current;
    }
    lst = NULL;
}