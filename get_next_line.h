/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:13:40 by ele-borg          #+#    #+#             */
/*   Updated: 2024/09/03 17:32:38 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include "push_swap.h"
# include "checker_bonus.h"

char	*get_next_line(int fd, t_list **lst_a, t_list **lst_b);
char	*clean_stash_buffer(char *stash, char *buffer, int *s);
char	*read_and_stock(int fd, char *line, char *buffer, int *n);
char	*ft_strdup(char *s);;
int		ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_free(char *s);

#endif