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

char *ft_calloc(char *s)
{
	char *save;
	int len;
	int i;

	i = 0;
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
	char		*s;
	int			ct;

	s = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	read(o, s, BUFFER_SIZE);
	ct = ft_find(s);
	save = ft_calloc(&s[ct]);
	if (!save)
		return (NULL);
	s[BUFFER_SIZE + 1] = 0;
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
