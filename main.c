#include"get_next_line_bonus.h"
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	int	fd1;
	int	fd2;
	int fd3;
	int fd4;

	fd1 = open("test/none", O_RDONLY);
	printf("fd1 = %d : none\n", fd1);
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd1));
	
	fd2 = open("test/just_nl", O_RDONLY);
	printf("fd2 = %d : just new line\n", fd2);
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));

	fd3 = open("test/sample1", O_RDONLY);
	printf("fd3 = %d : sample\n", fd3);
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd3));

	fd4 = open("test/longletter", O_RDONLY);
	printf("fd4 = %d : long letter\n", fd4);
	printf("%s", get_next_line(fd4));
	printf("%s", get_next_line(fd4));

	printf("AGAIN\nfd3 = %d : sample\n", fd3);
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd3));

	close (fd1);
	close (fd2);
	close (fd3);
	close (fd4);
	return (0);
}
