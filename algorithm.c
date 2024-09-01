/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:18:27 by marvin            #+#    #+#             */
/*   Updated: 2024/08/30 23:49:36 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotation_a(t_list **lst_a, long p_a)
{
	long	sense_a;

	sense_a = ft_define_sense_rotation_a(lst_a, p_a);
	while (p_a != 0 && p_a != ft_lstsize(lst_a))
	{
		if (sense_a == 1)
		{
			ft_rotate(lst_a);
			write(1, "ra\n", 3);
			p_a--;
		}
		if (sense_a == -1)
		{
			ft_reverse_rotate(lst_a);
			write(1, "rra\n", 4);
			p_a++;
		}
	}
}

void	ft_rotation_b(t_list **lst_b, long nmb_a)
{
	long	sense_b;

	sense_b = ft_define_sense_rotation_b(nmb_a, lst_b);
	while (ft_end_rot(nmb_a, lst_b) == 0)
	{
		if (sense_b == 1)
		{
			ft_rotate(lst_b);
			write(1, "rb\n", 3);
		}
		if (sense_b == -1)
		{
			ft_reverse_rotate(lst_b);
			write(1, "rrb\n", 4);
		}
	}
}

void	ft_b_rotation_and_push_to_a(t_list **lst_a, t_list **lst_b)
{
	long	sense_b;

	sense_b = ft_define_sense_rotation(lst_b);
	if (sense_b == 1)
	{
		while (ft_in_decresent_order(lst_b) == -1)
		{
			ft_rotate(lst_b);
			write(1, "rb\n", 3);
		}
	}
	else if (sense_b == -1)
	{
		while (ft_in_decresent_order(lst_b) == -1)
		{
			ft_reverse_rotate(lst_b);
			write(1, "rrb\n", 4);
		}
	}
	while (*lst_b != NULL)
	{
		ft_push_x_to_y(lst_b, lst_a);
		write(1, "pa\n", 3);
	}
}

void	ft_rotation_a_b(t_list **lst_a, t_list **lst_b, long nmb_a, long *p_a)
{
	long	sense_a;

	sense_a = ft_define_sense_rotation_a(lst_a, (*p_a));
	while ((*p_a) != 0 && (*p_a) != ft_lstsize(lst_a)
		&& ft_end_rot(nmb_a, lst_b) == 0)
	{
		if (sense_a == 1)
		{
			ft_rotate(lst_a);
			ft_rotate(lst_b);
			write(1, "rr\n", 3);
			(*p_a)--;
		}
		if (sense_a == -1)
		{
			ft_reverse_rotate(lst_a);
			ft_reverse_rotate(lst_b);
			write(1, "rrr\n", 4);
			(*p_a)++;
		}
	}
}

int	ft_atlgorithm(t_list **lst_a, t_list **lst_b)
{
	long	sense_b;
	long	sense_a;
	long	nmb_a;
	long	p_a;

	while (*lst_a != NULL)
	{
		p_a = 0;
		nmb_a = (*lst_a)-> content;
		ft_value_2_push(lst_a, lst_b, &p_a, &nmb_a);
		if (ft_lstsize(lst_a) == 1)
			p_a = 0;
		sense_b = ft_define_sense_rotation_b(nmb_a, lst_b);
		sense_a = ft_define_sense_rotation_a(lst_a, p_a);
		if (sense_a == sense_b)
			ft_rotation_a_b(lst_a, lst_b, nmb_a, &p_a);
		ft_rotation_a(lst_a, p_a);
		ft_rotation_b(lst_b, nmb_a);
		ft_push_x_to_y(lst_a, lst_b);
		write(1, "pb\n", 3);
	}
	return (ft_b_rotation_and_push_to_a(lst_a, lst_b), 0);
}
