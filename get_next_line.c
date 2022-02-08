/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:08:24 by lide              #+#    #+#             */
/*   Updated: 2022/02/08 16:17:34 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = read(fd, str, BUFFER_SIZE);
	if (i == -1)
		return (NULL);
	str[BUFFER_SIZE] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*str;
	char		*s;
	int			len;

	str = ft_read(fd);
	if (!str)
		return (NULL);
	s = ft_strjoin(save, str);
	if (!s || !*s)
		return (NULL);
	free(str);
	len = ft_find(s);
	save = ft_strdup(&s[len]);
	s[len] = 0;
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	return (str);
}
