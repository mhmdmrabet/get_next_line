#include "get_next_line.h"

int main (void)
{
	int i = 0;
	int fd = open("test.txt", O_RDONLY);
	while (i < 4)
	{
		char *line = get_next_line(fd);
		printf("LINE %d : %s\n", i, line);
		free(line);
		i++;
	}
	return (0);
}
