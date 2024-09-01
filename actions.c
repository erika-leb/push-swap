/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:45:23 by ele-borg          #+#    #+#             */
/*   Updated: 2024/08/30 23:51:02 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_list **lst_a, t_list **lst_b, t_list **lst_c)
{
	ft_lstclear(*lst_a);
	ft_lstclear(*lst_b);
	ft_lstclear(*lst_c);
	exit(1);
}

long	ft_value_a(t_list **lst_a, long p)
{
	long	val;
	long	p2;
	t_list	*current;

	val = 0;
	p2 = 0;
	current = *lst_a;
	while (p2 < p)
	{
		current = current -> next;
		p2++;
	}
	val = current -> content;
	return (val);
}

void	ft_simultaneous_actions(t_elements *elm)
{
	if (elm->sense_a == elm->sense_b)
	{
		while (*(elm->p) != 0 && *(elm->p) != ft_lstsize(elm->lst_a)
			&& ft_end_rot(elm->val, elm->lst_b) == 0)
		{
			if (elm->sense_a == 1)
				ft_nmb_rab(elm->lst_a, elm->lst_b, elm->lst_c, (elm->p));
			if (elm->sense_a == -1)
				ft_nmb_rrab(elm->lst_a, elm->lst_b, elm->lst_c, (elm->p));
			(*(elm->nmb))++;
		}
	}
}

void	ft_actions(t_elements *elm)
{
	int	r;

	r = 0;
	while (*(elm->p) != 0 && *(elm->p) != ft_lstsize(elm->lst_a))
	{
		r = ft_nmb_rotation_a(elm->lst_a, elm->lst_c, elm->p, (elm->nmb));
		if (r == 1)
			ft_clear(elm->lst_a, elm->lst_b, elm->lst_c);
	}
	while (ft_end_rot(elm->val, elm->lst_b) == 0)
	{
		r = ft_nbm_rotation_b(elm->lst_b, elm->lst_c, (elm->nmb), elm->sense_b);
		if (r == 1)
			ft_clear(elm->lst_a, elm->lst_b, elm->lst_c);
	}
}
