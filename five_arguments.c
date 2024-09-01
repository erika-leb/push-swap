/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:08:35 by ele-borg          #+#    #+#             */
/*   Updated: 2024/08/29 17:12:23 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_return_median(t_list **lst, long	*median)
{
	t_list	*current;
	t_list	*other;
	long	sup;
	long	inf;

	current = *lst;
	while (current != NULL)
	{
		other = *lst;
		sup = 0;
		inf = 0;
		while (other != NULL)
		{
			if (other -> content > current -> content)
				sup++;
			if (other -> content < current -> content)
				inf++;
			other = other -> next;
		}
		if (sup == 2 && inf == 2)
			(*median) = current -> content;
		current = current -> next;
	}
}

long	ft_position_little(t_list **lst_a, long median)
{
	t_list	*current;
	long	p;

	current = *lst_a;
	p = 0;
	while (current -> content >= median && current != NULL)
	{
		current = current -> next;
		p++;
	}
	return (p);
}

void	ft_put_to_b(t_list **lst_a, long median)
{
	long	p;

	p = ft_position_little(lst_a, median);
	if (p == 1 || p == 2)
	{
		while (p-- != 0)
		{
			ft_rotate(lst_a);
			write(1, "ra\n", 3);
		}
	}
	else if (p == ft_lstsize(lst_a) - 1 || p == ft_lstsize(lst_a) - 2)
	{
		while (p++ != ft_lstsize(lst_a))
		{
			ft_reverse_rotate(lst_a);
			write(1, "rra\n", 4);
		}
	}
}

void	ft_two_arguments_reverse(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	first = *lst;
	second = first -> next;
	if (first -> content < second -> content)
	{
		ft_rotate(lst);
		write(1, "rb\n", 3);
	}
}

void	ft_five_arguments(t_list **lst_a, t_list **lst_b)
{
	long	median;

	median = 0;
	ft_return_median(lst_a, &median);
	ft_put_to_b(lst_a, median);
	ft_push_x_to_y(lst_a, lst_b);
	write(1, "pb\n", 3);
	ft_put_to_b(lst_a, median);
	ft_push_x_to_y(lst_a, lst_b);
	write(1, "pb\n", 3);
	ft_three_arguments(lst_a);
	ft_two_arguments_reverse(lst_b);
	ft_push_x_to_y(lst_b, lst_a);
	ft_push_x_to_y(lst_b, lst_a);
	write(1, "pa\npa\n", 6);
}
