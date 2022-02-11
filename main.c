#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	char	*str;
	int		fd;
	// int		fd2;

	fd = open("text.txt", O_RDONLY);
	// fd2 = open("text2.txt", O_RDONLY);
	// fd = 0;
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	// str = get_next_line(fd);
	// printf("1 - |%s|\n", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("2 - |%s|\n", str);
	// free(str);
	// str = get_next_line(fd2);
	// printf("3 - |%s|\n", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("4 - |%s|\n", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("5 - |%s|\n", str);
	// free(str);
	// str = get_next_line(fd2);
	// printf("6 - |%s|\n", str);
	// free(str);
	// str = get_next_line(fd2);
	// printf("7 - |%s|\n", str);
	// free(str);
	close(fd);
	// close(fd2);
	return (0);
}

		// write(1, str, ft_strlen(str));
