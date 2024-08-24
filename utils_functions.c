/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:34:03 by marvin            #+#    #+#             */
/*   Updated: 2024/08/24 16:45:51 by ele-borg         ###   ########.fr       */
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
