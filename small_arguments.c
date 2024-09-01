/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:13:55 by ele-borg          #+#    #+#             */
/*   Updated: 2024/08/29 17:11:42 by ele-borg         ###   ########.fr       */
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
