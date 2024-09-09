/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:22:09 by ele-borg          #+#    #+#             */
/*   Updated: 2024/09/09 13:17:37 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line.h"

int	is_instructions(char *line, t_list **lst_a, t_list **lst_b, int t)
{
	if (!line)
		return (1);
	else if (ft_strcmp(line, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(line, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(line, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rra\n") == 0)
		return (1);
	else
		return (is_instructions_bis(line, lst_a, lst_b, t));
}

int	is_instructions_bis(char *line, t_list **lst_a, t_list **lst_b, int t)
{
	if (ft_strcmp(line, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		return (1);
	else
	{
		if (t == 0)
		{
			ft_lstclear(*lst_a);
			*lst_a = NULL;
			ft_lstclear(*lst_b);
			*lst_a = NULL;
		}
		return (0);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
