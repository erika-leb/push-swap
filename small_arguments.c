/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:13:55 by ele-borg          #+#    #+#             */
/*   Updated: 2024/08/15 13:36:49 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void two_arguments(t_list **lst)
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


void three_arguments(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *lst;
	second = first -> next;
	third = second -> next;
	        // printf("PILE A\n");
            // PRINT_STACK(lst);

	if (first -> content > second -> content && first -> content > third -> content)
	{
		ft_rotate(lst);
		write(1, "ra\n", 3);
	}
	    // printf("PILE A\n");
        //     PRINT_STACK(lst);
			// printf("first -> content = %ld\n", first -> content);
			// printf("second -> content = %ld\n", second -> content);
			// printf("third -> content = %ld\n", third -> content);
	if (second -> content > first -> content && second -> content > third -> content)
	{
		ft_swap(lst);
		write(1, "sa\n", 3);
		ft_rotate(lst);
		write(1, "ra\n", 3);
	}
	    // printf("PILE A\n");
        //     PRINT_STACK(lst);
	first = *lst;
	second = first -> next;
	third = second -> next;
	if (first -> content > second -> content)
	{
		ft_swap(lst);
		write(1, "sa\n", 3);
	}
	    // printf("PILE A\n");
        //     PRINT_STACK(lst);
}