#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
	int		fd;
	char	**line;

	fd = open("Text.txt", O_RDONLY);
	get_next_line(fd, line);
	return (0);
}