/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:51 by marvin            #+#    #+#             */
/*   Updated: 2024/08/19 15:48:03 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_three_in_a(t_list **lst)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	first = *lst;
	second = first -> next;
	if (ft_lstsize(lst) == 1)
		return ;
	if (ft_lstsize(lst) == 2)
	{
		if (first -> content > second -> content)
		{
			ft_swap(lst);
			write(1, "sa\n", 3);
		}
		return ;
	}
	last = ft_lstlast(*lst);
	while(!(first -> content < second -> content && first -> content < last -> content)) // tant que a n'est pas le plus petit des trois
	{
		if (second -> content < first -> content && second -> content < last -> content)
		{
			ft_swap(lst);
			write(1, "sa\n", 3);
		}
		if (last -> content < first -> content && last -> content <  second -> content)
		{
			ft_rotate(lst); // changer pour reverse ?
			write(1, "ra\n", 3);
		}
		first = *lst;
		second = first -> next;
		last = ft_lstlast(*lst);
	}
}

void	ft_rotate_a(t_list **lst, long d)
{
	int		q;
	int		i;
	t_list	*current;
	int		p;
	long	minus;

	p = -1;
	current = *lst;
	minus = ft_abs(current -> content - d);
	i = ft_lstsize(lst);
	if (i >= 1 && i <= 3)
	{
		ft_rotate_three_in_a(lst);
		return ;
	}
	//printf("i = %d\n", i);
	q = (float)i - (float)1 / (float) 16 * (float) i;  // mettre un printf pour verifier le resutlat et tester d'autres pourcentages
	//printf("q = %d\n", q);
	while (p != 0)
	{
		current = *lst;
		current = current -> next;
		if (ft_abs(current -> content - d) < minus)
			p = 1;
		//printf("current -> content = %ld, c = %ld\n", current -> content, c);
		//printf("p = %d\n", p);
		i = 1;
		while (i < q && current != NULL)
		{
			i++;
			current = current -> next;
		}
		while (current != NULL)
		{
			if (ft_abs(current -> content - d) < minus)
			{
				p = i;
				minus = ft_abs(current -> content - d);
			}
			//printf("current -> content = %ld, c = %ld\n", current -> content, c);
			//printf("p = %d\n", p);
			current = current -> next;
			i++;
		}
		current = *lst;
		//printf("current -> content = %ld, c = %ld\n", current -> content, c);
		if (minus == ft_abs(current -> content - d))
			p = 0;
		//printf("pfinal = %d\n", p);
		if (p == 1)
		{
			ft_swap(lst);
			write(1, "sa\n", 3);
			//printf("test1");
		}
		else if (p != 0)
		{
			ft_reverse_rotate(lst);
			write(1, "rra\n", 4);
		}
		//printf("p = %d\n", p);
	}
}