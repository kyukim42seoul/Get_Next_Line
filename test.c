#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main()
{
	int		read_size = 0;
	int		line_size = 0;
	int		fd = 0;
	int		check = 0;
	int		result = 0;
	char	buf[4];

	fd = open("Text.txt", O_RDONLY);
	while((read_size = read(fd, buf, 3)))
	{
		buf[3] = '\0';
		result = printf("check : %s\n", buf);
	}
	return (0);
}
