/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:51 by marvin            #+#    #+#             */
/*   Updated: 2024/07/24 14:38:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int int_check(int nv, char **arg)
{
    int i;
    int j;

    i = 1;
    while (i < nv)
    {
        j = 0;
        if (arg[i][0] == '+' || arg[i][0] == '-')
            j = 1;
        while (arg[i][j])
        {
            if (arg[i][j] < '0' || arg[i][j] > '9')
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_cmp_lst(int  content, t_list **lst, int i)
{
    t_list  *current;
    int     k;

    k = 0;
    current = *lst;
    while (current != NULL && k < i)
    {
        if (content == current -> content)
            return (-1);
        current = current -> next;
        k++;
    }
    return (0);
}

int check_double(t_list  **lst)
{
    t_list  *current;
    int     i;

    current = *lst;
    i = 0;
    while (current != NULL)
    {
        if (ft_cmp_lst(current -> content, lst, i) == -1)
            return (-1);
        current = current -> next;
        i++;
    }
    return (0);
}

int check_max_min(t_list  **lst)
{
    t_list  *current;
    int     i;

    current = *lst;
    i = 0;
    while (current != NULL)
    {
        if (current -> content > INT_MAX || current -> content < INT_MIN)
            return (-1);
        current = current -> next;
        i++;
    }
    return (0);
}

void    PRINT_STACK(t_list  **lst, int nv)
{
    t_list  *current;
    int v;
    int i;
        
    current = *lst;
    v = ft_lstsize(lst);
    i = 0;
    printf("taille = %d \n", v);
    while (current != NULL)
    {
        printf("valeur %d = %d\n", i, (current) -> content);
        current = current -> next;
        i++;
    }
}

int main(int nv, char **arg)
{
    int     i;
    t_list  *new;
    t_list  *lst_a;
    t_list  *lst_b;
    int     size;

    lst_a = NULL;
    lst_b = NULL;    
    if (nv > 1)
    {
        if (int_check(nv, arg) == -1)
            write(1, "Error\n", 6);
        else
        {
            i = 2;
            //j = 0;
            //printf("arg[1] = %s\n", arg[1]);
            //printf("ft_atoi(arg[1]) = %d\n", ft_atoi_simple(arg[1]));
            lst_a = ft_lstnew(ft_atoi_simple(arg[1]));
            //printf("lst 1 = %d\n", (lst_a[0]) -> content);
            while (i < nv)
            {
                new = ft_lstnew(ft_atoi_simple(arg[i]));
                ft_lstadd_back(&lst_a, new);
                //j++;
                //printf("*lst -> content = %d\n", (lst[j]) -> content);
                i++;
            }
            //ft_push_x_to_y(&lst_a, &lst_b);
            //ft_push_x_to_y(&lst_a, &lst_b);
            if (check_double(&lst_a) == -1 || check_max_min(&lst_a) == -1)
            {
                write(1, "Error\n", 6);
                return (0);
            }

            ft_atlgorithm(&lst_a, &lst_b);
            //printf("ën ordre? %d\n", ft_in_decresent_order(&lst_a));

            //JUSTE POUR TEST
            // printf("PILE A\n");
            // PRINT_STACK(&lst_a, nv);
            // printf("PILE B\n");
            // PRINT_STACK(&lst_b, nv);
            //FIN TEST
            ft_lstclear(lst_a);
            ft_lstclear(lst_b);
        }
    }
    return (0);
}