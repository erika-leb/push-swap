/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:51 by marvin            #+#    #+#             */
/*   Updated: 2024/09/01 16:28:28 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*ft_get_arg_in_lst(char *str, int *j)
// {
// 	long	i;
// 	long	r;
// 	t_list	*lst;
// 	t_list	*new;

// 	lst = NULL;
// 	i = 0;
// 	while (str && str[i] && str[i] >= 32 && str[i] <= 126)
// 	{
// 		r = ft_atoi_simple(str, &i);
// 		if (lst == NULL)
// 		{
// 			lst = ft_lstnew(r);
// 			if (lst == NULL)
// 				return (NULL);
// 		}
// 		else
// 		{
// 			new = ft_lstnew(r);
// 			if (new == NULL)
// 				return (NULL);
// 			ft_lstadd_back(&lst, new);
// 		}
// 		(*j)++;
// 	}
// 	return (lst);
// }

t_list	*ft_get_arg_in_lst(char *str, int *j)
{
	long	i;
	long	r;
	t_list	*lst;
	t_list	*new;

	i = 0;
	lst = NULL;
	while (str && str[i] && str[i] >= 32 && str[i] <= 126)
	{
		r = ft_atoi_simple(str, &i);
		new = ft_lstnew(r);
		if (!new)
			return (NULL);
		if (!lst)
			lst = new;
		else
			ft_lstadd_back(&lst, new);
		(*j)++;
	}
	return (lst);
}

int	ft_create_lst(t_list **lst, int nv, char **arg)
{
	int		i;
	t_list	*new;
	int		j;

	i = 2;
	j = 1;
	*lst = ft_get_arg_in_lst(arg[1], &j);
	if (*lst == NULL)
		exit(1);
	while (i < nv)
	{
		new = ft_get_arg_in_lst(arg[i], &j);
		if (new == NULL)
		{
			ft_lstclear(*lst);
			exit(1);
		}
		ft_lstadd_back(lst, new);
		i++;
	}
	return (j);
}

int	ft_case_management(int nv, t_list **lst_a, t_list **lst_b)
{
	int	r;

	if (nv == 3)
		ft_two_arguments(lst_a);
	else if (nv == 4)
		ft_three_arguments(lst_a);
	else if (nv == 6)
		ft_five_arguments(lst_a, lst_b);
	else
	{
		r = ft_atlgorithm(lst_a, lst_b);
		if (r == 1)
			return (1);
	}
	return (0);
}

int	main(int nv, char **arg)
{
	t_list		*lst_a;
	t_list		*lst_b;
	int			nb;

	lst_a = NULL;
	lst_b = NULL;
	if (nv > 1)
	{
		if (ft_int_check(nv, arg) == -1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		nb = ft_create_lst(&lst_a, nv, arg);
		if (ft_check_double(&lst_a) == -1 || ft_check_max_min(&lst_a) == -1)
		{
			write(2, "Error\n", 6);
			ft_lstclear(lst_a);
			return (0);
		}
		if (ft_in_cresent_order(&lst_a) == -1)
			ft_case_management(nb, &lst_a, &lst_b);
		(ft_lstclear(lst_a), ft_lstclear(lst_b));
	}
	return (0);
}

void	print_stack(t_list **lst)
{
	t_list	*current;
	int		i;

	current = *lst;
	i = 0;
	while (current != NULL)
	{
		printf("valeur %d = %ld\n", i, current -> content);
		current = current -> next;
		i++;
	}
}
