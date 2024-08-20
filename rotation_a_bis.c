/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_a_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:51 by marvin            #+#    #+#             */
/*   Updated: 2024/08/19 19:17:24 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	undo_instructions(t_list **lst_b, t_list **lst_c)
{
	t_list	*current;

	current = *lst_c;
	while (current != NULL)
	{
		if (current -> content == 1)
			ft_reverse_rotate(lst_b);
		if (current -> content == 2)
			ft_rotate(lst_b);
		current = current -> next;
	}
}

long	case_a(t_list **lst_a, t_list **lst_b)
{
	long		nmb;
	long		sense_check;
	t_list		*lst_c;

	nmb = 0;
	lst_c = NULL;
	sense_check = define_sense_rotation((*lst_a) -> content, lst_b);
	if (sense_check == 1)
		nmb = nmb + ft_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	if (sense_check == 0)
		nmb = nmb + ft_reverse_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	undo_instructions(lst_b, &lst_c);
	ft_lstclear(lst_c);
	//printf("nmba = %ld\n", nmb);
	return (nmb);
}

long	case_b(t_list **lst_a, t_list **lst_b)
{
	long		nmb;
	long		sense_check;
	t_list		*lst_c;

	nmb = 1;
	lst_c = NULL;
	ft_swap(lst_a);
	sense_check = define_sense_rotation((*lst_a) -> content, lst_b);
	if (sense_check == 1)
		nmb = nmb + ft_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	if (sense_check == 0)
		nmb = nmb + ft_reverse_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	undo_instructions(lst_b, &lst_c);
	ft_lstclear(lst_c);
	ft_swap(lst_a);
	//printf("nmbd = %ld\n", nmb);
	return (nmb);
}

long	case_c(t_list **lst_a, t_list **lst_b)
{
	long		nmb;
	long		sense_check;
	t_list		*lst_c;

	nmb = 1;
	lst_c = NULL;
	ft_reverse_rotate(lst_a);
	sense_check = define_sense_rotation((*lst_a) -> content, lst_b);
	if (sense_check == 1)
		nmb = nmb + ft_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	if (sense_check == 0)
		nmb = nmb + ft_reverse_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	undo_instructions(lst_b, &lst_c);
	ft_lstclear(lst_c);
	ft_rotate(lst_a);
	//printf("nmbc = %ld\n", nmb);
	return (nmb);
}

void	ft_rotate_a_bis(t_list **lst_a, t_list **lst_b)
{
	long	nmb_a;
	long	nmb_b;
	long	nmb_c;

	nmb_a = case_a(lst_a, lst_b);
	nmb_b = case_b(lst_a, lst_b);
	nmb_c = case_c(lst_a, lst_b);

	//printf("na = %ld, nb = %ld, nc = %ld\n", nmb_a, nmb_b, nmb_c);
	if (nmb_a <= nmb_b && nmb_a <= nmb_c)
		return ;
	else if (nmb_b < nmb_a && nmb_b < nmb_c)
	{
		ft_swap(lst_a);
		write(1, "sa\n", 3);
	}
	else
	{
		ft_reverse_rotate(lst_a);
		write(1, "rra\n", 4);
	}
}