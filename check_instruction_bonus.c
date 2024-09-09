/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:22:09 by ele-borg          #+#    #+#             */
/*   Updated: 2024/09/09 13:15:50 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line.h"

void	ft_checker(t_list **lst_a, t_list **lst_b)
{
	char	*line;

	line = get_next_line(0, lst_a, lst_b);
	if (line == NULL)
	{
		if (ft_in_cresent_order(lst_a) != -1)
			write(1, "OK\n", 3);
		else if (is_instructions(line, lst_a, lst_b, 0) == 1)
			write(1, "KO\n", 3);
	}
	else
	{
		while (line != NULL)
		{
			ft_apply_instruction_a(line, lst_a, lst_b);
			free(line);
			line = get_next_line(0, lst_a, lst_b);
		}
		ft_check_in_order(lst_a, lst_b);
	}
	free(line);
}

void	ft_apply_instruction_a(char *line, t_list **lst_a, t_list **lst_b)
{
	if (ft_strcmp(line, "pa\n") == 0)
		ft_push_x_to_y(lst_b, lst_a);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push_x_to_y(lst_a, lst_b);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_swap(lst_b);
	else if (ft_strcmp(line, "sa\n") == 0)
		ft_swap(lst_a);
	else if (ft_strcmp(line, "ss\n") == 0)
	{
		ft_swap(lst_a);
		ft_swap(lst_b);
	}
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_rotate(lst_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rotate(lst_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_reverse_rotate(lst_a);
	else
		return (ft_apply_instruction_b(line, lst_a, lst_b));
}

void	ft_apply_instruction_b(char *line, t_list **lst_a, t_list **lst_b)
{
	if (ft_strcmp(line, "rrb\n") == 0)
		ft_reverse_rotate(lst_b);
	else if (ft_strcmp(line, "rr\n") == 0)
	{
		ft_rotate(lst_a);
		ft_rotate(lst_b);
	}
	else if (ft_strcmp(line, "rrr\n") == 0)
	{
		ft_reverse_rotate(lst_a);
		ft_reverse_rotate(lst_b);
	}
	else
	{
		write(2, "Error\n", 6);
		ft_lstclear(*lst_a);
		ft_lstclear(*lst_b);
		free(line);
		exit (1);
	}
}

void	ft_check_void(t_list **lst_a, t_list **lst_b)
{
	if (ft_lstsize(lst_b) != 0)
	{
		write(1, "KO\n", 3);
		ft_lstclear(*lst_a);
		ft_lstclear(*lst_b);
		exit (1);
	}
}

void	ft_check_in_order(t_list **lst_a, t_list **lst_b)
{
	t_list	*first;
	t_list	*second;

	first = *lst_a;
	second = first -> next;
	ft_check_void(lst_a, lst_b);
	if (ft_lstsize(lst_a) == 0 || ft_lstsize(lst_a) == 1)
	{
		write(1, "OK\n", 3);
		return ;
	}
	while (second != NULL)
	{
		if (first -> content > second -> content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		first = first -> next;
		second = second -> next;
	}
	write(1, "OK\n", 3);
}
