
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    char    *str;
    int    fd;
	// int    fd2;
	// int    fd3;
	// int    fd4;
    fd = 0;
    while ((str = get_next_line(fd)))
    {
        printf("%s", str);
        free (str);
    }
    // fd1 = open("get_next_line.c", O_RDONLY);
	// fd2 = open("get_next_line.h", O_RDONLY);
	// fd3 = open("get_next_line_utils.c", O_RDONLY);
    // fd4 = open("text.txt", O_RDONLY);
	// str = get_next_line(fd1);
    // printf("fd1 %s", str);
    // free(str);
	// str = get_next_line(fd2);
    // printf("fd2 %s", str);
    // free(str);
	// str = get_next_line(fd3);
    // printf("fd3 %s", str);
    // free(str);
	// str = get_next_line(fd4);
    // printf("fd4 %s", str);
    // free(str);
	// str = get_next_line(fd2);
    // printf("fd2 %s", str);
    // free(str);
	// str = get_next_line(fd4);
    // printf("%s", str);
    // free(str);
	// str = get_next_line(fd3);
    // printf("fd3 %s", str);
    // free(str);
	// str = get_next_line(fd1);
    // printf("fd1 %s", str);
    // free(str);
    close(fd);
	// close(fd2);
	// close(fd3);
	// close(fd4);
    return (0);
}
