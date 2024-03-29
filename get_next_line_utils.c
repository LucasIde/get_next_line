/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:08:17 by lide              #+#    #+#             */
/*   Updated: 2022/03/02 16:52:29 by lide             ###   ########.fr       */
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

int	ft_find(char *s)
{
	int	ct;

	ct = 0;
	while (s[ct])
	{
		if (s[ct] == '\n')
			return (ct + 1);
		ct++;
	}
	return (ct);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_line(char *save, int len)
{
	char	*s1;
	int		i;

	if (!*save)
	{
		free(save);
		return (NULL);
	}
	s1 = malloc(sizeof(char) * (len + 1));
	if (!s1)
	{
		free(save);
		return (NULL);
	}
	i = -1;
	while (++i < len)
		s1[i] = save[i];
	s1[i] = 0;
	return (s1);
}

char	*ft_save(char *save, int len)
{
	char	*s2;
	int		len_2;
	int		j;

	len_2 = ft_strlen(&save[len]);
	s2 = malloc(sizeof(char) * (len_2 + 1));
	if (!s2)
	{
		free(save);
		return (NULL);
	}
	j = 0;
	while (save[len])
		s2[j++] = save[len++];
	s2[j] = 0;
	free(save);
	return (s2);
}
