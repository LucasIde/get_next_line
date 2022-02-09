#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int o;
	char *tmp;

	o = open("text.txt", O_RDONLY);
	tmp = get_next_line(o);
	while (tmp)
	{
		// printf("%s", tmp);
	free(tmp);
	tmp = get_next_line(o);
	}
	// printf("fin du programme");
	return (0);
}
