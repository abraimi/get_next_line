#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>

int main(void)
{
	char *line;
	int	fd;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
}