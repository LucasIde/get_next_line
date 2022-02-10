#include "get_next_line.h"
#include <stdio.h>

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

	if (!s)
		return (0);
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

char	*ft_read(int fd, char *save)
{
	char	*str;
	int		i;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
		str[i] = 0;
		save = ft_strjoin(save, str, -1, -1);
	}
	free(str);
	return (save);
}

char *ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*s3;

	if (!s1)
	{
		s3 = malloc(sizeof(char) * (ft_strlen(s2) + 1));
		if (!s3)
			return (0);
		while (s2[++i])
			s3[i] = s2[i];
		s3[i] = 0;
		return (s3);
	}
	else
	{
		s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!s3)
			return (0);
		while (s1[++i])
			s3[i] = s1[i];
		while (s2[++j])
			s3[i++] = s2[j];
		s3[i] = 0;
		free(s1);
		return (s3);
	}
}

char *ft_split(char *save, char **line,int j)
{
	char *s1;
	char *s2;
	int len;
	int i;

	if (!save || !*save)
		return (NULL);
	i = -1;
	len = ft_find(save);
	s1 = malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	while (++i < len)
		s1[i] = save[i];
	s1[i++] = 0;
	len = ft_strlen(&save[len]);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (save[i])
		s2[++j] = save[i];
	s2[j] = 0;
	free(save);
	line = &s1;
	return (s1);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*s;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	save = ft_split(save, &line, -1);
	if (!save)
	{
		free(save);
		return (NULL);
	}
	return (line);
}
