/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:08:17 by lide              #+#    #+#             */
/*   Updated: 2022/02/09 18:17:01 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i++] = s2[j];
	s3[i] = 0;
	free(s1);
	return (s3);
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

char	*ft_strdup(char *s)
{
	char	*save;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	save = malloc(sizeof(char) * len + 1);
	if (!save)
		return (NULL);
	save[len] = 0;
	while (s[i])
	{
		save[i] = s[i];
		i++;
	}
	return (save);
}

int	ft_find(char *s)
{
	int	ct;

	ct = 0;
	while (s[ct] && s[ct] != '\n')
		ct++;
	if (s[ct] == '\n')
		ct++;
	return (ct);
}
