/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_to_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:05:08 by ele-borg          #+#    #+#             */
/*   Updated: 2024/08/31 00:23:42 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_undo_instr(t_list **lst_a, t_list **lst_b, t_list **lst_c)
{
	t_list	*current;

	current = *lst_c;
	while (current != NULL)
	{
		if (current -> content == 1)
			ft_reverse_rotate(lst_b);
		if (current -> content == 2)
			ft_rotate(lst_b);
		if (current -> content == 3)
			ft_reverse_rotate(lst_a);
		if (current -> content == 4)
			ft_rotate(lst_a);
		if (current -> content == 5)
		{
			ft_reverse_rotate(lst_a);
			ft_reverse_rotate(lst_b);
		}
		if (current -> content == 6)
		{
			ft_rotate(lst_a);
			ft_rotate(lst_b);
		}
		current = current -> next;
	}
}

int	ft_put_in_lst_c(t_list **lst_c, long n)
{
	t_list		*new;

	if (*lst_c == NULL)
	{
		*lst_c = ft_lstnew(n);
		if (*lst_c == NULL)
			return (1);
	}
	else
	{
		new = ft_lstnew(n);
		if (new == NULL)
			return (1);
		ft_lstadd_front(lst_c, new);
	}
	return (0);
}

void	ft_value_2_push(t_list **lst_a, t_list **lst_b, long *pmin, long *vmin)
{
	long	nmb_current;
	long	nmb_min;
	long	p;
	t_list	*curr;

	nmb_min = 0;
	nmb_current = 0;
	p = 0;
	curr = *lst_a;
	ft_instructions_nmb(lst_a, lst_b, p, &nmb_min);
	while (p < ft_lstsize(lst_a))
	{
		ft_instructions_nmb(lst_a, lst_b, p, &nmb_current);
		if (nmb_min > nmb_current)
		{
			(*vmin) = curr -> content;
			(*pmin) = p;
			nmb_min = nmb_current;
		}
		curr = curr -> next;
		p++;
	}
}
