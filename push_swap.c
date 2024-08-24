/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:51 by marvin            #+#    #+#             */
/*   Updated: 2024/08/24 18:01:14 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_arg_in_lst(char *str)
{
	long	i;
	long	r;
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	i = 0;
	if (!str)
		return(NULL);
	while (str[i] && str[i] >= 32 && str[i] <= 126)
	{
		r = ft_atoi_simple(str, &i);
		new = ft_lstnew(r);
		if (new == NULL)
			return (NULL);
		if (lst != NULL)
			ft_lstadd_back(&lst, new);
		else
		{
			lst = ft_lstnew(r);
			if (lst == NULL)
				return (NULL);
		}
	}
	return (lst);
}

void	case_management(int nv, t_list	**lst_a, t_list	**lst_b)
{
	if (nv == 3) // 2 argument
		two_arguments(lst_a);
	else if (nv == 4) // 3 arguments
		three_arguments(lst_a);
	else if (nv > 4)
		ft_atlgorithm(lst_a, lst_b);
    // //JUSTE POUR TEST
            printf("PILE A\n");
            PRINT_STACK(lst_a);
            printf("PILE B\n");
            PRINT_STACK(lst_b);
     // //FIN TEST
	 	//printf("MIN INT = %d, MAX INT = %d\n", INT_MIN, INT_MAX);
	ft_lstclear(*lst_a);
	ft_lstclear(*lst_b);
}

int	create_lst(t_list **lst, int nv, char **arg)
{
	int		i;
	t_list	*new;

	i = 2;
	*lst = ft_get_arg_in_lst(arg[1]);
	if (lst == NULL)
		return (1);
	while (i < nv)
	{
		new = ft_get_arg_in_lst(arg[i]);
		ft_lstadd_back(lst, new);
		i++;
	}
	return (0);
}

int	main(int nv, char **arg)
{
	t_list		*lst_a;
	t_list		*lst_b;
	int			j;

	lst_a = NULL;
	lst_b = NULL;    
	if (nv > 1)
	{
		if (int_check(nv, arg) == -1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		j = create_lst(&lst_a, nv, arg);
		if (j == 1)
			return (1);
		if (check_double(&lst_a) == -1 || check_max_min(&lst_a) == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		case_management(nv, &lst_a, &lst_b);
	}
	return (0);
}

void    PRINT_STACK(t_list  **lst) // a enlever a la fin
{
    t_list  *current;
    //int v;
    int i;
        
    current = *lst;
	//printf("test\n");
    //v = ft_lstsize(lst);
    i = 0;
    //printf("taille = %d \n", v);
	//printf("test\n");
    while (current != NULL)
    {
        printf("valeur %d = %ld\n", i, (current) -> content);
        current = current -> next;
        i++;
    }
}
