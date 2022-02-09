/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:08:24 by lide              #+#    #+#             */
/*   Updated: 2022/02/09 18:16:58 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	backspace(char *s)
{
	int	ct;

	if (!s)
		return (1);
	ct = -1;
	while (s[++ct])
	{
		if (s[ct] == '\n')
			return (0);
	}
	return (1);
}

char	*ft_read(int fd,char *save)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (backspace(save) && i)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[BUFFER_SIZE] = 0;
		save = ft_strjoin(save, str);
		if (!save || !*save)
			return (NULL);
	}
	free(str);
	str = ft_strdup(save);
	free(save);
	if (!str)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*str;
	char		*s;
	int			len;

	str = ft_read(fd, save);
	if (!str)
		return (NULL);
	len = ft_find(str);
	save = ft_strdup(&str[len]);
	str[len] = 0;
	s = ft_strdup(str);
	free(str);
	if (!s)
		return (NULL);
	return (s);
}
