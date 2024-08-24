/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:51 by marvin            #+#    #+#             */
/*   Updated: 2024/08/23 14:41:00 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	undo_instructions(t_list **lst_a, t_list **lst_b, t_list **lst_c)
{
	t_list	*current;

	current = *lst_c;
	// printf("analyse undo\n");
	// printf("PILE C\n");
    // PRINT_STACK(lst_c);
	while (current != NULL)
	{
		if (current -> content == 1)
		{
			ft_reverse_rotate(lst_b);
			//printf("rrb cache (defaire)\n");
		}
		if (current -> content == 2)
		{
			ft_rotate(lst_b);
			//printf("rb cache(defaire)\n");
		}
		if (current -> content == 3)
		{
			ft_reverse_rotate(lst_a);
			//printf("rra cache(defaire)\n"); //ici
		}
		if (current -> content == 4)
		{
			ft_rotate(lst_a);
			//printf("ra cache (defaire)\n");
		}
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
	undo_instructions(lst_a, lst_b,&lst_c);
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
	//printf("sa cache (faire)\n");
	sense_check = define_sense_rotation((*lst_a) -> content, lst_b);
	if (sense_check == 1)
		nmb = nmb + ft_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	if (sense_check == 0)
		nmb = nmb + ft_reverse_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	undo_instructions(lst_a, lst_b, &lst_c);
	ft_lstclear(lst_c);
	ft_swap(lst_a);
	//printf("sa cache (defaire)\n");
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
	//printf("rra cache (faire)\n");
	sense_check = define_sense_rotation((*lst_a) -> content, lst_b);
	if (sense_check == 1)
		nmb = nmb + ft_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	if (sense_check == 0)
		nmb = nmb + ft_reverse_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	undo_instructions(lst_a, lst_b, &lst_c);
	ft_lstclear(lst_c);
	ft_rotate(lst_a);
	//printf("ra cache (defaire)\n");
	//printf("nmbc = %ld\n", nmb);
	return (nmb);
}

void	case_3_in_a(t_list **lst_a, t_list **lst_b)
{
	long	nmb_a;
	long	nmb_b;
	long	nmb_c;

	nmb_a = case_a(lst_a, lst_b);
	nmb_b = case_b(lst_a, lst_b);
	nmb_c = case_c(lst_a, lst_b);

	//printf("na = %ld, nb = %ld, nc = %ld\n", nmb_a, nmb_b, nmb_c);
	if (nmb_a <= nmb_b && nmb_a <= nmb_c)
	{
		//printf("case 3 in a, pas de mouvements sur a\n");
		return ;
	}
	else if (nmb_b < nmb_a && nmb_b < nmb_c)
	{
		ft_swap(lst_a);
		write(1, "sa\n", 3);
			// 		printf("PILE A\n");
            // PRINT_STACK(lst_a);
            // printf("PILE B\n");
            // PRINT_STACK(lst_b);
	}
	else
	{
		ft_reverse_rotate(lst_a);
		write(1, "rra\n", 4);
			// 		printf("PILE A\n");
            // PRINT_STACK(lst_a);
            // printf("PILE B\n");
            // PRINT_STACK(lst_b);
	}
	//printf("case 3 in a, mouvements sur a\n");
    // printf("PILE A\n");
	// PRINT_STACK(lst_a);
    // printf("PILE B\n");
    // PRINT_STACK(lst_b);
}

long	case_general(t_list **lst_a, t_list **lst_b, long p)
{
	long		nmb;
	long		sense_check;
	t_list		*lst_c;
	t_list		*new;

	nmb = 0;
	lst_c = NULL;
	if (p <= ft_lstsize(lst_a) / 2)
	{
		//printf("bon cas, ft_lstsize(lst_a) / 2 = %d\n", ft_lstsize(lst_a) / 2);
		while (p != 0)
		{
			ft_rotate(lst_a);
			nmb++;
			if (lst_c == NULL)
			{
				lst_c = ft_lstnew(3); // 3 == ra
				//printf("mauvais cas\n");
			}
			else
			{
				new = ft_lstnew(3);
				ft_lstadd_front(&lst_c, new);
				//printf("bon cas\n");
			}
	 		//printf("ra cache (faire) \n");
	// printf("PILE C\n");
    // PRINT_STACK(&lst_c);
			p--;
		}
	}
	else
	{
		//printf("mauvais cas, ft_lstsize(lst_a) / 2 = %d\n", ft_lstsize(lst_a) / 2);
		while (p != ft_lstsize(lst_a))
		{
			ft_reverse_rotate(lst_a);
			if (lst_c == NULL)
				lst_c = ft_lstnew(4); // 4 == rra
			else
			{
				new = ft_lstnew(4);
				ft_lstadd_front(&lst_c, new);
			}
			nmb++;
			//printf("rra cache (faire)\n"); //ici
			p++;
		}
	}
	//printf("nmb en a = %ld\n", nmb);
	sense_check = define_sense_rotation((*lst_a) -> content, lst_b);
	//printf("sense = %ld, (*lst_a) -> content = %ld\n", sense_check, (*lst_a) -> content);
	// printf("PILE B\n");
    // PRINT_STACK(lst_b);
	if (sense_check == 1)
		nmb = nmb + ft_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	if (sense_check == 0)
		nmb = nmb + ft_reverse_rotate_b_without_print((*lst_a) -> content, lst_b, &lst_c);
	//printf("PILE C\n");
    //PRINT_STACK(&lst_c);
	undo_instructions(lst_a, lst_b, &lst_c);
	ft_lstclear(lst_c);
	return (nmb);	
}

void	ft_rotate_a(t_list **lst_a, t_list **lst_b)
{
	long	nmb_current;
	long	nmb_min;
	long	p;
	long	p_min;

	if (ft_lstsize(lst_a) == 1 || ft_lstsize(lst_a) == 2)
	{
		return ;
		//printf("case 1 ou 2, pas de mouvements sur a\n");
	}
	if (ft_lstsize(lst_a) == 3)
	{
		case_3_in_a(lst_a, lst_b);
	}
	else
	{
		p = 0;
		p_min = 0;
		nmb_min = case_general(lst_a, lst_b, p);
		// printf("on est dans ft_rotate_a_bis dans le cas else\n");
		// printf("stacks avant modif :\n");
		// printf("PILE A\n");
		// PRINT_STACK(lst_a);
    	// printf("PILE B\n");
    	// PRINT_STACK(lst_b);
		while (p < ft_lstsize(lst_a))
		{
					//printf("stacks intermediaire :\n");
		// printf("PILE A\n");
		// PRINT_STACK(lst_a);
    	// printf("PILE B\n");
    	// PRINT_STACK(lst_b);
			nmb_current = case_general(lst_a, lst_b, p);
			//printf("nmb_min = %ld, nmb_current = %ld, p = %ld, p_min = %ld\n", nmb_min, nmb_current, p, p_min);
			if (nmb_min > nmb_current)
			{
				nmb_min = nmb_current;
				p_min = p;
			}
			p++;
		}
		//printf("p_min = %ld, nmb_min = %ld\n", p_min, nmb_min);
		// printf("stacks apres modif :\n");
		// printf("PILE A\n");
		// PRINT_STACK(lst_a);
    	// printf("PILE B\n");
    	// PRINT_STACK(lst_b);
		if (p_min == 0)
			return ;
		if (p_min == 1)
		{
			ft_swap(lst_a);
			write(1, "sa\n", 3);
			// 			printf("PILE A\n");
            // PRINT_STACK(lst_a);
            // printf("PILE B\n");
            // PRINT_STACK(lst_b);
		}
		else
		{
			if (p_min <= ft_lstsize(lst_a) / 2)
				while (p_min != 0)
				{
					ft_rotate(lst_a);
					write(1, "ra\n", 3);
			// 					printf("PILE A\n");
            // PRINT_STACK(lst_a);
            // printf("PILE B\n");
            // PRINT_STACK(lst_b);
					p_min--;
				}
			else
				while (p_min != ft_lstsize(lst_a))
				{
					ft_reverse_rotate(lst_a);
			 		write(1, "rra\n", 4);
			// 		printf("PILE A\n");
            // PRINT_STACK(lst_a);
            // printf("PILE B\n");
            // PRINT_STACK(lst_b);
					p_min++;
				}
		}
	}
}
