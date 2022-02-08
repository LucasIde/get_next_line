#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int ft_find(char *s)
{
	int	ct;

	ct = 0;
	while(s[ct] && s[ct] != '\n')
		ct++;
	return (ct);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *s)
{
	char *save;
	int len;
	int i;

	i = 0;
	if (!s)
		return (NULL);
	if (s[i] == '\n')
		i++;
	len = ft_strlen(s);
	save = malloc(sizeof(char) * len);
	if (!save)
		return (NULL);
	while (i < len)
	{
		save[i] = s[i];
		i++;
	}
	return (save);
}

char *print(int o)
{
	static char	*save = 0;
	char		*line;
	char		*s;
	int			ct;

	s = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	read(o, s, BUFFER_SIZE);
	ct = ft_find(s);
	line = ft_strdup(&s[ct]);
	if (!save)
		return (NULL);
	save = line;
	free(line);
	s[ct] = 0;
	return (s);
}

int main(void)
{
	int o;
	char *tmp;

	o = open("text.txt", O_RDONLY);
	tmp = print(o);
	while (tmp)
	{
		printf("%s\n", tmp);
		free(tmp);
		tmp = print(o);
	}
	return (0);
}


// #include "get_next_line.h"

// char *ft_recup(char *save)
// {
// 	char	*line
// 	int		len;

// 	if (save != 0);
// 	{
// 		len = ft_strlen(save);
// 		line = malloc(sizeof(char) * (len + 1));
// 		if (!line)
// 			return (NULL);
// 		//copy save to line
// 		//free save
// 	}
// 	else
// 	{
// 		line = malloc(sizeof(char));
// 		line[0] = 0;
// 	}
// }
