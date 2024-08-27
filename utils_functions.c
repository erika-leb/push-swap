/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:34:03 by marvin            #+#    #+#             */
/*   Updated: 2024/08/27 14:26:29 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

long	ft_atoi_simple(char *str, long *i)
{
		long	sign;
		long	r;
		
		sign = 1;
		r = 0;
		while (str[*i] == ' ')
			(*i)++;
		if (str[*i] == '+' || str[*i] == '-')
		{
			if (str[*i] == '-')
				sign = -1;
			(*i)++;
		}
		while (str[*i] >= '0' && str[*i] <= '9')
		{
				r = r * 10 + str[*i] - '0';
				(*i)++;
		}
		while (str[*i] == ' ')
			(*i)++;
		return (r * sign);
}			

long	ft_abs(long nmb)
{
	if (nmb < 0)
		return (- nmb);
	else
		return (nmb);
}

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

