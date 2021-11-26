#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int main (void)
{
	int i;
	int fd;
	char *line;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
//	while(1);
}
