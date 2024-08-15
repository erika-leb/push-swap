/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:18:27 by marvin            #+#    #+#             */
/*   Updated: 2024/08/15 18:29:37 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_in_cresent_order(t_list **lst) // retourne 0 si ordonnee, -1 sinon, pour la stack A!
{
	t_list	*next;
	t_list	*current;

	current = *lst;
	next = current -> next;
	while (next != NULL)
	{
		if (current -> content > next -> content)
			return (-1);
		current = next;
		next = next -> next;
	}
	return (0);
}

int	ft_in_decresent_order(t_list **lst) // retourne 0 si ordonnee, -1 sinon, pour la stack B!
{
	t_list	*next;
	t_list	*current;

	current = *lst;
	next = current -> next;
	while (next != NULL)
	{
		if (current -> content < next -> content)
			return (-1);
		current = next;
		next = next -> next;
	}
	return (0);
}

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

// en cours
void	ft_rotate_a(t_list **lst)
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

int     verif(t_list **lst)
{
    int i;
    t_list  *current;
    t_list  *next;

    i = 0;
    current = *lst;
    next = current -> next;
    while (next != NULL)
    {
        if (next -> content > current -> content)
            i++;
        current = current -> next;
        next = next -> next;
    }
    return (i);
}

long	define_sense_rotation(int nmb_a, t_list **lst)
{
	long 	r;
	long	i;
	long 	j;
	t_list  *current;
	long	diff;

	i = 0;
	if (ft_lstsize(lst) == 0)
		return (-1);
	current = *lst;
	while (current != NULL)
	{
		if (ft_abs(nmb_a - current -> content) < diff) //mettre a la valeur absolue
		{
			diff = ft_abs(nmb_a - current -> content);
			j = i;
		}
		current = current -> next;
		i++;
	}
	// printf("i = %ld, j = %ld\n", i, j);
	diff = (float)(((float)j / (float)i) * 100);
	// printf("j / i * 100 = %ld\n",diff);
	if (diff >= 50.0)
		r = 0;
	else
		r = 1;
	//printf("r = %ld\n",r);
	return (r);
}

void	ft_atlgorithm(t_list **lst_a, t_list **lst_b)
{
	long	sense_check;

	if (ft_in_cresent_order(lst_a) == -1)
	{
		while (*lst_a != NULL) //on met tout a dans b
		{
            //printf("n = %d\n", (*lst_a) -> content);
			//ft_rotate_a(lst_a);
			sense_check = define_sense_rotation((*lst_a) -> content, lst_b);
			if (sense_check == 1)
			{
				ft_rotate_b((*lst_a) -> content, lst_b); //on fait tourner b pour qu'il soit dans le bon sens
				//printf("rotate\n");
			}
			if (sense_check == 0)
			{
			 	ft_reverse_rotate_b((*lst_a) -> content, lst_b);
				//printf("reverse-rotate\n");
			}
			ft_push_x_to_y(lst_a, lst_b); //on met a sur b
			write(1, "pb\n", 3);
			// printf("PILE A\n");
            // PRINT_STACK(lst_a);
            // printf("PILE B\n");
            // PRINT_STACK(lst_b);
            // printf("n = %d\n", (*lst_a) -> content);
            // ft_rotate_b((*lst_a) -> content, lst_b);
            // ft_push_x_to_y(lst_a, lst_b);
            // printf("n = %d\n", (*lst_a) -> content);
            // ft_rotate_b((*lst_a) -> content, lst_b);
            // ft_push_x_to_y(lst_a, lst_b);
            // printf("n = %d\n", (*lst_a) -> content);
            // ft_rotate_b((*lst_a) -> content, lst_b);
            // ft_push_x_to_y(lst_a, lst_b);
            // printf("n = %d\n", (*lst_a) -> content);
            // ft_rotate_b((*lst_a) -> content, lst_b);
            // ft_push_x_to_y(lst_a, lst_b);
            // printf("n = %d\n", (*lst_a) -> content);
            // ft_rotate_b((*lst_a) -> content, lst_b);
            // ft_push_x_to_y(lst_a, lst_b);
		}
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
		while (*lst_b != NULL) // mettre tout b dans a
		{
			ft_push_x_to_y(lst_b, lst_a);
			write(1, "pa\n", 3);
		}
	}
}