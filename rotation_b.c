/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:51 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 18:15:06 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_two(int nmb_a, t_list **lst)
{
	t_list	*first;
	t_list	*second;

	first = *lst;
	second = first -> next;
	if (nmb_a > second -> content && nmb_a > first -> content && first -> content < second -> content)
	{
		ft_rotate(lst);
		write(1, "rb\n", 3);
	}
	if (nmb_a < second -> content && nmb_a < first -> content && second -> content > first -> content)
	{
		ft_rotate(lst);
		write(1, "rb\n", 3);
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
		write(1, "rb\n", 3);
		//printf("cas 4\n");
	}
}

void	ft_rotate_b(int nmb_a, t_list **lst) // peut etre ameliore en choisissant le sens de rotation       utilite:fqire pivoter B comme je veux
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (*lst == NULL || ft_lstsize(lst) == 1)
		return ;
	first = *lst;
	second = first -> next;
	if (ft_lstsize(lst) == 2)
	{
		ft_rotate_two(nmb_a, lst);
		return ;
	}
	last = ft_lstlast(*lst);
	while (1)
	{
	if (nmb_a > first -> content && nmb_a < last -> content)
	{
		//printf("cas 1");
		return ;
	}
	if (nmb_a > first -> content && ft_in_decresent_order(lst) == 0)
	{
		//printf("cas 2");
		return ;
	}
	if (nmb_a < last -> content && ft_in_decresent_order(lst) == 0)
	{
		//printf("cas 3");
		return ;
	}
	else
	{
		ft_rotate(lst);
		write(1, "rb\n", 3);
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
}

void	ft_reverse_rotate_b(int nmb_a, t_list **lst) // peut etre ameliore en choisissant le sens de rotation       utilite:fqire pivoter B comme je veux
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (*lst == NULL || ft_lstsize(lst) == 1)
		return ;
	first = *lst;
	second = first -> next;
	if (ft_lstsize(lst) == 2)
	{
		ft_rotate_two(nmb_a, lst);
		return ;
	}
	last = ft_lstlast(*lst);
	while (1)
	{
	if (nmb_a > first -> content && nmb_a < last -> content)
	{
		//printf("cas 1");
		return ;
	}
	if (nmb_a > first -> content && ft_in_decresent_order(lst) == 0)
	{
		//printf("cas 2");
		return ;
	}
	if (nmb_a < last -> content && ft_in_decresent_order(lst) == 0)
	{
		//printf("cas 3");
		return ;
	}
	else
	{
		ft_reverse_rotate(lst);
		write(1, "rrb\n", 4);
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
}