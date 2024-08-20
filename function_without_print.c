/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_without_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:50:19 by marvin            #+#    #+#             */
/*   Updated: 2024/08/19 18:47:03 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


long	ft_rotate_two_without_print(int nmb_a, t_list **lst, t_list **lst_c)
{
	t_list	*first;
	t_list	*second;
	long	nmb;

	first = *lst;
	second = first -> next;
	nmb = 0;
	if (nmb_a > second -> content && nmb_a > first -> content && first -> content < second -> content)
	{
		ft_rotate(lst);
		*lst_c = ft_lstnew(1); // 1 == rb
	}
	if (nmb_a < second -> content && nmb_a < first -> content && second -> content > first -> content)
	{
		ft_rotate(lst);
		*lst_c = ft_lstnew(1);
		nmb++;
		//printf("cas 2\n");
	}
	// if (nmb_a < second -> content && nmb_a < first -> content && second -> content < first -> content)
	// {
	// 	ft_rotate(lst);
	// 	printf("cas 3\n");
	// }
	if (first -> content > nmb_a && nmb_a > second -> content)
	{
		ft_rotate(lst);
		*lst_c = ft_lstnew(1);
		//printf("cas 4\n");
		nmb++;
	}
	return (nmb);
}

long	ft_rotate_b_without_print(int nmb_a, t_list **lst, t_list **lst_c) // peut etre ameliore en choisissant le sens de rotation       utilite:fqire pivoter B comme je veux
{
	t_list	*first;
	t_list	*last;
	t_list	*second;
	t_list	*new;
	long	nmb;

	if (*lst == NULL || ft_lstsize(lst) == 1)
		return (0);
	first = *lst;
	nmb = 0;
	second = first -> next;
	if (ft_lstsize(lst) == 2)
	{
		nmb = ft_rotate_two_without_print(nmb_a, lst, lst_c);
		return (nmb);
	}
	last = ft_lstlast(*lst);
	while (1)
	{
	if (nmb_a > first -> content && nmb_a < last -> content)
	{
		//printf("cas 1");
		return (0);
	}
	if (nmb_a > first -> content && ft_in_decresent_order(lst) == 0)
	{
		//printf("cas 2");
		return (0);
	}
	if (nmb_a < last -> content && ft_in_decresent_order(lst) == 0)
	{
		//printf("cas 3");
		return (0);
	}
	else
	{
		ft_rotate(lst);
		if (*lst_c == NULL)
			*lst_c = ft_lstnew(1);
		else
		{
			new = ft_lstnew(1);
			ft_lstadd_front(lst_c, new);
		}
		nmb++;
		//printf("k\n");
	}
    //printf("nmb = %d, ft = %d\n", nmb_a, ft_in_decresent_order(lst));
	first = *lst;
	last = ft_lstlast(*lst);
	}
	printf("nmb dans la fonction = %ld\n", nmb);
	return (nmb);
}

long	ft_reverse_rotate_b_without_print(int nmb_a, t_list **lst, t_list **lst_c)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;
	long	nmb;
	t_list	*new;

	if (*lst == NULL || ft_lstsize(lst) == 1)
		return (0);
	first = *lst;
	nmb = 0;
	second = first -> next;
	if (ft_lstsize(lst) == 2)
	{
		nmb = ft_rotate_two_without_print(nmb_a, lst, lst_c);
		return (nmb);
	}
	last = ft_lstlast(*lst);
	while (1)
	{
	if (nmb_a > first -> content && nmb_a < last -> content)
	{
		//printf("cas 1");
		return (nmb);
	}
	if (nmb_a > first -> content && ft_in_decresent_order(lst) == 0)
	{
		//printf("cas 2");
		return (nmb);
	}
	if (nmb_a < last -> content && ft_in_decresent_order(lst) == 0)
	{
		//printf("cas 3");
		return (nmb);
	}
	else
	{
		ft_reverse_rotate(lst);
		if (*lst_c == NULL)
			*lst_c = ft_lstnew(2); // 2 == rrb
		else
		{
			new = ft_lstnew(2);
			ft_lstadd_front(lst_c, new);
		}
		nmb++;
		//printf("k\n");
	}
    //printf("nmb = %d, ft = %d\n", nmb_a, ft_in_decresent_order(lst));
	first = *lst;
	last = ft_lstlast(*lst);
    //printf("fist = %d, last = %d\n", first->content, last->content);
	}

    // while (first -> content < last -> content) // remettre dans lórdrem pqs tres utle
    // {
    //     ft_rotate(lst);
    //     first = *lst;
    //     last = ft_lstlast(*lst);
    // }
	printf("nmb dans la fonction = %ld\n", nmb);
	return (nmb);
}