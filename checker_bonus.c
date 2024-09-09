/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:16:47 by ele-borg          #+#    #+#             */
/*   Updated: 2024/09/02 17:47:55 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line.h"

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
			ft_lstclear(lst_b);
			return (0);
		}
		ft_checker(&lst_a, &lst_b);
		(ft_lstclear(lst_a), ft_lstclear(lst_b));
	}
	return (0);
}
