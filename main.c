#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	// write(1, "PAR ICI\n", 8);
    // printf("salut");
    char    *str;
    int    fd;

    // fd = open("text.txt", O_RDONLY);
    fd = 0;
    while ((str = get_next_line(fd)))
    {
        printf("%s", str);
        // free(str);
    }
    close(fd);
    return (0);
}

		// write(1, str, ft_strlen(str));
