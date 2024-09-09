/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions_parta.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:32:21 by marvin            #+#    #+#             */
/*   Updated: 2024/09/02 23:34:52 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
	{
		write(2, "Erreur memory allocation\n", 26);
		return (NULL);
	}
	new -> content = content;
	new -> next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list **lst)
{
	int		s;
	t_list	*current;

	s = 0;
	current = *lst;
	if (*lst == NULL)
		return (0);
	while (current != NULL)
	{
		s++;
		current = current -> next;
	}
	return (s);
}
