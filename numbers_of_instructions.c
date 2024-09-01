/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_of_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:51 by marvin            #+#    #+#             */
/*   Updated: 2024/08/30 23:48:27 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nmb_rab(t_list **lst_a, t_list **lst_b, t_list **lst_c, long *p)
{
	int	r;

	ft_rotate(lst_a);
	ft_rotate(lst_b);
	r = ft_put_in_lst_c(lst_c, 5);
	if (r == 1)
		ft_clear(lst_a, lst_b, lst_c);
	(*p)--;
	return (0);
}

int	ft_nmb_rrab(t_list **lst_a, t_list **lst_b, t_list **lst_c, long *p)
{
	int	r;

	ft_reverse_rotate(lst_a);
	ft_reverse_rotate(lst_b);
	r = ft_put_in_lst_c(lst_c, 6);
	if (r == 1)
		ft_clear(lst_a, lst_b, lst_c);
	(*p)++;
	return (0);
}

int	ft_nmb_rotation_a(t_list **lst_a, t_list **lst_c, long *p, long *nmb)
{
	int		r;
	long	sense_a;

	sense_a = ft_define_sense_rotation_a(lst_a, (*p));
	if (sense_a == 1)
	{
		ft_rotate(lst_a);
		r = ft_put_in_lst_c(lst_c, 3);
		if (r == 1)
			return (1);
		(*p)--;
	}
	if (sense_a == -1)
	{
		ft_reverse_rotate(lst_a);
		r = ft_put_in_lst_c(lst_c, 4);
		if (r == 1)
			return (1);
		(*p)++;
	}
	(*nmb)++;
	return (0);
}

int	ft_nbm_rotation_b(t_list **lst_b, t_list **lst_c, long *nb, long sense)
{
	int	r;

	if (sense == 1)
	{
		ft_rotate(lst_b);
		r = ft_put_in_lst_c(lst_c, 1);
		if (r == 1)
			return (1);
		(*nb)++;
	}
	if (sense == -1)
	{
		ft_reverse_rotate(lst_b);
		r = ft_put_in_lst_c(lst_c, 2);
		if (r == 1)
			return (1);
		(*nb)++;
	}
	return (0);
}

void	ft_instructions_nmb(t_list **lst_a, t_list **lst_b, long p, long *nmb)
{
	t_list		*lst_c;
	long		sense_b;
	long		sense_a;
	long		val;
	t_elements	elements;

	val = ft_value_a(lst_a, p);
	(*nmb) = 0;
	lst_c = NULL;
	sense_b = ft_define_sense_rotation_b(val, lst_b);
	sense_a = ft_define_sense_rotation_a(lst_a, p);
	elements.lst_a = lst_a;
	elements.lst_b = lst_b;
	elements.lst_c = &lst_c;
	elements.sense_b = sense_b;
	elements.val = val;
	elements.nmb = nmb;
	elements.sense_a = sense_a;
	elements.p = &p;
	ft_simultaneous_actions(&elements);
	ft_actions(&elements);
	ft_undo_instr(lst_a, lst_b, &lst_c);
	ft_lstclear(lst_c);
}
