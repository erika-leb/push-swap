/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:13:55 by ele-borg          #+#    #+#             */
/*   Updated: 2024/09/02 21:58:40 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_two_arguments(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	first = *lst;
	second = first -> next;
	if (first -> content > second -> content)
	{
		ft_rotate(lst);
		write(1, "ra\n", 3);
	}
}

void	ft_instructions(long i, t_list **lst)
{
	if (i == 1)
	{
		ft_rotate(lst);
		write(1, "ra\n", 3);
	}
	if (i == 2)
	{
		ft_swap(lst);
		write(1, "sa\n", 3);
		ft_rotate(lst);
		write(1, "ra\n", 3);
	}
	if (i == 3)
	{
		ft_swap(lst);
		write(1, "sa\n", 3);
	}
}

void	ft_three_arguments(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *lst;
	second = first -> next;
	third = second -> next;
	if (first -> content > second -> content
		&& first -> content > third -> content)
		ft_instructions(1, lst);
	if (second -> content > first -> content
		&& second -> content > third -> content)
		ft_instructions(2, lst);
	first = *lst;
	second = first -> next;
	third = second -> next;
	if (first -> content > second -> content)
		ft_instructions(3, lst);
}

int	ft_find_min_index(t_list *lst)
{
	int		min_index;
	int		index;
	int		min_value;
	t_list	*current;

	if (lst == NULL)
		return (-1);
	min_value = lst->content;
	min_index = 0;
	index = 0;
	current = lst;
	while (current != NULL)
	{
		if (current->content < min_value)
		{
			min_value = current->content;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

void	ft_four_arguments(t_list **lst_a, t_list **lst_b)
{
	int	min_index;

	min_index = ft_find_min_index(*lst_a);
	if (min_index == 1)
	{
		ft_rotate(lst_a);
		write(1, "ra\n", 3);
	}
	else if (min_index == 2)
	{
		ft_rotate(lst_a);
		write(1, "ra\n", 3);
		ft_rotate(lst_a);
		write(1, "ra\n", 3);
	}
	else if (min_index == 3)
	{
		ft_reverse_rotate(lst_a);
		write(1, "rra\n", 4);
	}
	ft_push_x_to_y(lst_a, lst_b);
	write(1, "pb\n", 3);
	ft_three_arguments(lst_a);
	ft_push_x_to_y(lst_b, lst_a);
	write(1, "pa\n", 3);
}
