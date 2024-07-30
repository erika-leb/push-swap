/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:34:03 by marvin            #+#    #+#             */
/*   Updated: 2024/07/25 15:34:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

int ft_atoi_simple(char *str)
{
	int	i;
	int	sign;
	int	r;

	i = 0;
	sign = 1;
	r = 0;
    if (!str)
        return(0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
					sign = -1;
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
			r = r * 10 + str[i] - '0';
			i++;
	}
	return (r * sign);
}