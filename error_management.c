/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:48:33 by ele-borg          #+#    #+#             */
/*   Updated: 2024/08/24 16:50:28 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_check(int nv, char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (i < nv)
	{
		j = 0;
		while (arg[i][j])
		{
			while (arg[i][j] == ' ')
				j++;
			if (arg[i][j] == '+' || arg[i][j] == '-')
				j++;
			if (!(arg[i][j] >= '0' && arg[i][j] <= '9'))
				return (-1);
			while (arg[i][j] >= '0' && arg[i][j] <= '9')
				j++;
			while (arg[i][j] == ' ')
				j++;	
		}
		if (arg[i][j] != '\0')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_cmp_lst(int  content, t_list **lst, int i)
{
	t_list	*current;
	int		k;

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

int	check_double(t_list  **lst)
{
	t_list	*current;
	int		i;

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

int	check_max_min(t_list  **lst)
{
	t_list	*current;
	int		i;

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
