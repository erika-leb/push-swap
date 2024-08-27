/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sense_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:51 by marvin            #+#    #+#             */
/*   Updated: 2024/08/27 18:10:52 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_define_sense_rotation_a(t_list **lst, long p)
{
	//printf("p = %ld, ft_lstsize(lst) / 2 = %d\n", p, ft_lstsize(lst) / 2);
	if  (p <= ft_lstsize(lst) / 2)
		return (1);
	else
		return (-1);
}

long	ft_define_sense_rotation_b(int nmb_a, t_list **lst)
{
	long	i;
	long 	j;
	t_list  *current;
	long	diff;

	i = 0;
	if (ft_lstsize(lst) == 0)
		return (-1);
	current = *lst;
	j = 0;
	diff = ft_abs(nmb_a - (current -> content));
	while (current != NULL)
	{
		if (ft_abs(nmb_a - current -> content) < diff) //mettre a la valeur absolue
		{
			diff = ft_abs(nmb_a - (current -> content));
			j = i;
		}
		//printf("nmb_a dans fonction = %d, current -> content = %ld, diff = %ld, j = %ld, i = %ld\n", nmb_a, (current -> content), diff, j, i);
		current = current -> next;
		i++;
	}
	diff = (float)(((float)j / (float)i) * 100);
	if (diff >= 50.0)
		return (-1);
	else
		return (1);
}

long	ft_end_of_rotation_b(long nmb_a, t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (*lst == NULL || ft_lstsize(lst) == 1)
		return (1);
	first = *lst;
	last = ft_lstlast(*lst);
	//printf("nmb_a = %ld, first = %ld, last = %ld \n", nmb_a, first -> content, last -> content);
	if (nmb_a > first -> content && nmb_a < last -> content)
		return (1);
	if (nmb_a > first -> content && ft_in_decresent_order(lst) == 0)
		return (1);
	if (nmb_a < last -> content && ft_in_decresent_order(lst) == 0)
		return (1);
	else
		return (0);
}

long	ft_define_sense_rotation(t_list **lst)
{
	t_list	*current;
	long	i;
	long	min;
	long	size;
	long	i_min;

	i = 0;
	i_min = 0;
	current = *lst;
	size = ft_lstsize(lst);
	min = current -> content;
	while (i < size)
	{
		if (current -> content < min)
		{
			min = current -> content;
			i_min = i;
		}
		i++;
		current = current -> next;
	}
	if (i_min < size / 2)
		return (1); // sens vers le haut r necessaire
	else
		return (-1); // sens vers le bas rr necessaire
}