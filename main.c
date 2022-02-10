#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    // printf("salut");
    char    *str;
    int    fd;

    // fd = open("text.txt", O_RDONLY);
	// write(1, "PAR ICI\n", 8);
    fd = 0;
    while ((str = get_next_line(fd)))
    {
		// write(1, str, ft_strlen(str));
        printf("%s", str);
        free(str);
    }
    close(fd);
    return (0);
}
