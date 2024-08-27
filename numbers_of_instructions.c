/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_of_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:51 by marvin            #+#    #+#             */
/*   Updated: 2024/08/27 18:12:38 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_undo_instructions(t_list **lst_a, t_list **lst_b, t_list **lst_c)
{
	t_list	*current;

	current = *lst_c;
	// printf("analyse undo\n");
	// printf("PILE C\n");
    // PRINT_STACK(lst_c);
	while (current != NULL)
	{
		if (current -> content == 1)     // rb fait et rrb a faire
		{
			ft_reverse_rotate(lst_b);
			//printf("rrb cache (defaire)\n");
		}
		if (current -> content == 2)     // rrb fait et rb a faire
		{
			ft_rotate(lst_b);
			//printf("rb cache(defaire)\n");
		}
		if (current -> content == 3)      // ra fait et rra a faire
		{
			ft_reverse_rotate(lst_a);
			//printf("rra cache(defaire)\n"); //ici
		}
		if (current -> content == 4)      // rra fait et ra a faire
		{
			ft_rotate(lst_a);
			//printf("ra cache (defaire)\n");
		}
		if (current -> content == 5) // rr fait et rrr a faire
		{
			ft_reverse_rotate(lst_a);
			ft_reverse_rotate(lst_b);
			//printf("ra cache (defaire)\n");
		}
		if (current -> content == 6) // // rrr fait et rr a faire
		{
			ft_rotate(lst_a);
			ft_rotate(lst_b);
			//printf("ra cache (defaire)\n");
		}
		current = current -> next;
	// 		printf("PILE C4\n");
   	//  PRINT_STACK(lst_c);
	}
}

void	ft_put_in_lst_c(t_list **lst_c, long n)  //rqjouter la securite pour la liste chainee
{
	t_list		*new;

	if (lst_c == NULL)
	{
		*lst_c = ft_lstnew(n);
	}
	else
	{
		new = ft_lstnew(n);
		ft_lstadd_front(lst_c, new);
	}
}
long	ft_numbers_of_instructions(t_list **lst_a, t_list **lst_b, long p, long value)
{
	long	nmb;
	t_list	*lst_c;
	long	sense_b;
	long	sense_a;
	
	nmb = 0;
	lst_c = NULL;

	//printf("p = %ld, value = %ld\n", p, value);
	sense_b = ft_define_sense_rotation_b(value, lst_b);
	sense_a = ft_define_sense_rotation_a(lst_a, p);
	//printf("sense_b = %ld, p = %ld\n", sense_b, p);
	if (sense_a == sense_b)
	{
		while (p != 0 && p != ft_lstsize(lst_a) && ft_end_of_rotation_b(value, lst_b) == 0) // aucune des deux n a termine de tourner
		{
			if (sense_a == 1)
			{
				ft_rotate(lst_a);
				ft_rotate(lst_b);
				ft_put_in_lst_c(&lst_c, 5);
				p--;
				nmb++;
			}
			if (sense_a == -1)
			{
				ft_reverse_rotate(lst_a);
				ft_reverse_rotate(lst_b);
				ft_put_in_lst_c(&lst_c, 6);
				p++;
				nmb++;
			}
		}
	}
	//printf("nmb apres les rr = %ld\n", nmb);
	while (p != 0 && p != ft_lstsize(lst_a))// b a termine de tourner ? 1 = oui ; 0 = non
	{
		if (sense_a == 1)
		{
			ft_rotate(lst_a);
			ft_put_in_lst_c(&lst_c, 3);
			p--;
			nmb++;
		}
		if (sense_a == -1)
		{
			ft_reverse_rotate(lst_a);
			ft_put_in_lst_c(&lst_c, 4);
			p++;
			nmb++;
		}
	}
	//printf("nmb apres les ra = %ld\n", nmb);
	while (ft_end_of_rotation_b(value, lst_b) == 0)// b a termine de tourner ? 1 = oui ; 0 = non
	{
		//printf("oui ? %ld\n", ft_end_of_rotation_b(value, lst_b));
		//printf("sense_b = %ld\n", sense_b);
		if (sense_b == 1)
		{
			ft_rotate(lst_b);
			ft_put_in_lst_c(&lst_c, 1);
			nmb++;
		}
		if (sense_b == -1)
		{
			ft_reverse_rotate(lst_b);
			ft_put_in_lst_c(&lst_c, 2);
			nmb++;
		}
	}
	//printf("nmb apres les rb = %ld\n", nmb);
	ft_undo_instructions(lst_a, lst_b, &lst_c);
	ft_lstclear(lst_c);
	return (nmb);	
}

void	ft_define_value_to_push(t_list **lst_a, t_list **lst_b, long *p_min, long *value_min)
{
	long	nmb_current;
	long	nmb_min;
	long	p;
	t_list	*current;
	
	if (ft_lstsize(lst_a) == 1)
		return ;
	else
	{
		p = 0;
		current = *lst_a;
		nmb_min = ft_numbers_of_instructions(lst_a, lst_b, p, (*lst_a) -> content);
		//printf("p_min = %ld\n", *p_min);
		while (p < ft_lstsize(lst_a))
		{
			nmb_current = ft_numbers_of_instructions(lst_a, lst_b, p, current -> content);
			//printf("nmb_min = %ld, nmb_current = %ld, p = %ld, p_min = %ld\n", nmb_min, nmb_current, p, *p_min);
			//printf("value_min = %ld, value_current = %ld\n", *value_min, current -> content);
			if (nmb_min > nmb_current)
			{
				(*value_min) = current -> content;
				(*p_min) = p;
				nmb_min = nmb_current;
			}
			current = current -> next;
			//printf("test\n");
			//printf("value_min = %ld, value_current = %ld\n", *value_min, current -> content);
			p++;
			//printf("p = %ld, ft_lstsize(lst_a) = %d\n", p, ft_lstsize(lst_a));
		}
	}
}
