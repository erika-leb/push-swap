/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:18:27 by marvin            #+#    #+#             */
/*   Updated: 2024/08/27 18:12:14 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int     verif(t_list **lst)    // a supprimer plus tard
// {
//     int i;
//     t_list  *current;
//     t_list  *next;

//     i = 0;
//     current = *lst;
//     next = current -> next;
//     while (next != NULL)
//     {
//         if (next -> content > current -> content)
//             i++;
//         current = current -> next;
//         next = next -> next;
//     }
//     return (i);
// }

void	ft_atlgorithm(t_list **lst_a, t_list **lst_b)
{
	long	sense_b;
	long	sense_a;
	long	nmb_a;
	long	p_a;

	if (ft_in_cresent_order(lst_a) == -1)
	{
		while (*lst_a != NULL)
		{
			p_a = 0;
			nmb_a = (*lst_a) -> content;
			//////////////// DEFINIR QUEL NMB DE A METTRE SUR B  ////////////////////
			ft_define_value_to_push(lst_a, lst_b, &p_a, &nmb_a);
			//printf("value_a = %ld, p_a = %ld\n", nmb_a, p_a);
			if (ft_lstsize(lst_a) == 1)    //probablement inutile
				p_a = 0;

		    //////////////// ROTATION DE A ET B AVANT PUSH A SUR B  ////////////////////
			sense_b = ft_define_sense_rotation_b(nmb_a, lst_b);
			sense_a = ft_define_sense_rotation_a(lst_a, p_a);
			if (sense_a == sense_b)
			{
				while (p_a != 0 && p_a != ft_lstsize(lst_a) && ft_end_of_rotation_b(nmb_a, lst_b) == 0) // aucune des deux n a termine de tourner
				{
					if (sense_a == 1)
					{
						ft_rotate(lst_a);
						ft_rotate(lst_b);
						write(1, "rr\n", 3);
						p_a--;
					}
					if (sense_a == -1)
					{
						ft_reverse_rotate(lst_a);
						ft_reverse_rotate(lst_b);
						write(1, "rrr\n", 4);
						p_a++;
					}
				}
			}
			while (p_a != 0 && p_a != ft_lstsize(lst_a))// b a termine de tourner ? 1 = oui ; 0 = non
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

			while (ft_end_of_rotation_b(nmb_a, lst_b) == 0)// b a termine de tourner ? 1 = oui ; 0 = non
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

			// 		if (*lst_b != NULL && ft_lstsize(lst_a) > 1)
			// {
			// 	ft_rotate_a(lst_a, lst_b);
			// }

		///////////////////////////   PUSH A SUR B  ////////////////////
			ft_push_x_to_y(lst_a, lst_b);
			write(1, "pb\n", 3);
			//             printf("PILE A\n");
            // PRINT_STACK(lst_a);
            // printf("PILE B\n");
            // PRINT_STACK(lst_b);
		}
	}
		//////////////// ROTATION DE B POUR PREPARER LA MISE DANS A  ////////////////////
		sense_b = ft_define_sense_rotation(lst_b);
		if (sense_b == 1)
		{
			while (ft_in_decresent_order(lst_b) == -1) // on fait tourner b jusqu'a ce qu'il soit dans l'ordre
			{
				ft_rotate(lst_b);
				write(1, "rb\n", 3);
            // printf("PILE A\n");
            // PRINT_STACK(lst_a);
            // printf("PILE B\n");
            // PRINT_STACK(lst_b);
            // if (verif(lst_b) > 1)
            //     break;
			}
		}
		else if (sense_b == -1)
		{
			while (ft_in_decresent_order(lst_b) == -1) // on fait tourner b jusqu'a ce qu'il soit dans l'ordre
			{
				ft_reverse_rotate(lst_b);
				write(1, "rrb\n", 4);
			}
		}
		//////////////// MISE DE B DANS A  ////////////////////
		while (*lst_b != NULL)
		{
			ft_push_x_to_y(lst_b, lst_a);
			write(1, "pa\n", 3);
		}
	}
