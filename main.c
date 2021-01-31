#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int		fd;
	int		result;
	char	**line;
	char	*test_str;
	char	*buf_1;
	char	*buf_2;
	char	*buf_3;

	buf_1 = (char *)malloc(sizeof(char) * 5);
	buf_2 = (char *)malloc(sizeof(char) * 3);
	buf_3 = (char *)malloc(sizeof(char) * 10);

	fd = open("Text.txt", O_RDONLY);

//	gnl_strlen check / Ok(basic, null, 1 cases)
/*
	printf("%d\n", gnl_strlen("Hello"));
	printf("%d\n", gnl_strlen(""));
	printf("%d\n", gnl_strlen("1"));
*/

//	merge_line check / Ok(basic, empty, null cases)
/*
	test_str = merge_line("Hello", "world");
	printf("%s\n", test_str);
*/

//	check_next_line check / KO / Ok move buf++ position out of else to inside else
/*
	printf("%s\n%s\n%s\n", buf_1, buf_2, buf_3);
	printf("%d %d %d\n", check_next_line(buf_1), check_next_line(buf_2), check_next_line(buf_3));
*/

//	check while for find \n
	while ((result = read(fd, buf_1, 3))) // 파일 전체를 read
	{
		if(check_next_line(buf_1))
		{
			printf("check : %s\n", buf_1);
		}
		else
			printf("else : %s\n", buf_1);
	}
	free(buf_1);
	free(buf_2);
	free(buf_3);
	return (0);
}