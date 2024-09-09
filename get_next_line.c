/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:13:37 by ele-borg          #+#    #+#             */
/*   Updated: 2024/09/04 17:52:43 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker_bonus.h"
#include "push_swap.h"

char	*ft_free(char *s)
{
	free(s);
	s = NULL;
	return (s);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*clean_stash_buffer(char *stash, char *buffer, int *n)
{
	int		i;
	int		j;
	char	*temp;

	i = ft_strchr(buffer, '\n');
	j = ft_strchr(stash, '\n');
	if (j != -1)
	{
		temp = ft_substr(stash, j + 1, ft_strlen(stash) - j - 1);
		free(stash);
		stash = ft_strdup(temp);
		return (free(temp), free(buffer), stash);
	}
	else
	{
		if (stash != NULL)
			free(stash);
		stash = NULL;
		if (i != -1)
			stash = ft_substr(buffer, i + 1, *n - i - 1);
		return (free(buffer), stash);
	}
}

char	*read_and_stock(int fd, char *line, char *buffer, int *n)
{
	int			i;
	int			f;
	char		*temp;
	char		*tmp;

	i = -1;
	while (i == -1 && *n == BUFFER_SIZE && ft_strchr(line, '\n') == -1)
	{
		*n = read(fd, buffer, BUFFER_SIZE);
		if (*n == -1)
			return (NULL);
		i = ft_strchr(buffer, '\n');
		f = (*n);
		if (*n != 0)
		{
			if (i != -1)
				f = i + 1;
			tmp = ft_substr(buffer, 0, f);
			temp = ft_strdup(line);
			free(line);
			line = ft_strjoin(temp, tmp);
			(free(temp), free(tmp));
		}
	}
	return (line);
}

char	*get_next_line(int fd, t_list **la, t_list **lb)
{
	char		*buffer;
	static char	*stash = NULL;
	char		*line;
	int			n;

	if (fd == -1 || BUFFER_SIZE < 0 || read(fd, stash, 0) < 0)
	{
		if (stash != NULL)
			stash = ft_free(stash);
		return (NULL);
	}
	n = BUFFER_SIZE;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = NULL;
	if (stash != NULL && stash[0] != '\0' && ft_strchr(stash, '\n') == -1)
		line = ft_strdup(stash);
	else if (stash != NULL && stash[0] != '\0' && ft_strchr(stash, '\n') != -1)
		line = ft_substr(stash, 0, ft_strchr(stash, '\n') + 1);
	line = read_and_stock(fd, line, buffer, &n);
	stash = clean_stash_buffer(stash, buffer, &n);
	if (line == NULL || line[0] == '\n' || is_instructions(line, la, lb, 1) == 0)
		ft_free (stash);
	return (line);
}
