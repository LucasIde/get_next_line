// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include "get_next_line.h"

// int	backspace(char *s)
// {
// 	int	ct;

// 	if (!s)
// 		return (1);
// 	ct = -1;
// 	while (s[++ct])
// 	{
// 		if (s[ct] == '\n')
// 			return (0);
// 	}
// 	return (1);
// }

// char	*ft_read(int fd, char *save)
// {
// 	char	*str;
// 	int		i;
// 	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 1;
// 	while (backspace(save) && i)
// 	{
// 		i = read(fd, str, BUFFER_SIZE);
// 		if (i == -1)
// 		{
// 			free(str);
// 			return (NULL);
// 		}
// 		str[i] = 0;
// 		save = ft_strjoin(save, str, -1, -1);
// 	}
// 	free(str);
// 	str = ft_strdup(save);
// 	free(save);
// 	if (!str)
// 		return (NULL);
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*save;
// 	char		*str;
// 	char		*s;
// 	int			len;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	str = ft_read(fd, save);
// 	if (!str)
// 		return (NULL);
// 	len = ft_find(str);
// 	save = ft_strdup(&str[len]);
// 	str[len] = 0;
// 	s = ft_strdup(str);
// 	free(str);
// 	return (s);
// }

// #include "get_next_line.h"

// char	*ft_strjoin(char *s1, char *s2, int i, int j)
// {
// 	char	*s3;

// 	if (!s1)
// 	{
// 		s1 = malloc(sizeof(char));
// 		if (!s1)
// 			return (NULL);
// 		s1[0] = 0;
// 	}
// 	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!s3)
// 	{
// 		free(s1);
// 		return (NULL);
// 	}
// 	while (s1[++i])
// 		s3[i] = s1[i];
// 	while (s2[++j])
// 		s3[i++] = s2[j];
// 	s3[i] = 0;
// 	free(s1);
// 	return (s3);
// }

// int	ft_strlen(char *s)
// {
// 	int	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(char *s)
// {
// 	char	*save;
// 	int		len;
// 	int		i;

// 	if (!s || !*s)
// 		return (NULL);
// 	i = 0;
// 	len = ft_strlen(s);
// 	save = malloc(sizeof(char) * len + 1);
// 	if (!save)
// 		return (NULL);
// 	save[len] = 0;
// 	while (s[i])
// 	{
// 		save[i] = s[i];
// 		i++;
// 	}
// 	return (save);
// }

// int	ft_find(char *s)
// {
// 	int	ct;

// 	if (!s)
// 		return (0);
// 	ct = 0;
// 	while (s[ct])
// 	{
// 		if (s[ct] == '\n')
// 			return (ct + 1);
// 		ct++;
// 	}
// 	return (ct);
// }
