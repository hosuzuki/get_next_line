#include"get_next_line.h"
#include"get_next_line_bonus.h"
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
	int	fd5;
	int	fd6;

	if (argc > 1)
	{
		(void)argv[0];
		printf("<std input test>\n");
		printf("%s", get_next_line(0));
		return (0);
	}	

	printf("<passing 42 as fd>\n");
	printf("%s\n", get_next_line(42));
	
	fd1 = open("test/empty", O_RDONLY);
	printf("<empty : fd1 = %d>\n", fd1);
	printf("%s\n", get_next_line(fd1));
	
	fd2 = open("test/just_nl", O_RDONLY);
	printf("<just new line : fd2 = %d>\n", fd2);
	printf("%s", get_next_line(fd2));

	fd3 = open("test/3chara", O_RDONLY);
	printf("<3 charactors : fd3 = %d>\n", fd3);
	printf("%s", get_next_line(fd3));

	fd4 = open("test/1chara", O_RDONLY);
	printf("<1 charactor : fd4 = %d>\n", fd4);
	printf("%s", get_next_line(fd4));

	fd5 = open("test/longletter", O_RDONLY);
	printf("<long letter : fd5 = %d>\n", fd5);
	printf("%s", get_next_line(fd5));

	fd6 = open("test/over2k", O_RDONLY);
	printf("<2k+ characters : fd6 = %d>\n", fd6);
	printf("%s", get_next_line(fd6));

	printf("\n---BONUS---\n");
		
	printf("<long letter : fd5 = %d>\n", fd5);
	printf("%s", get_next_line(fd5));

	printf("<empty : fd1 = %d>\n", fd1);
	printf("%s\n", get_next_line(fd1));
	
	printf("<just new line : fd2 = %d>\n", fd2);
	printf("%s", get_next_line(fd2));

	printf("<3 charactors : fd3 = %d>\n", fd3);
	printf("%s", get_next_line(fd3));

	printf("<1 charactor : fd4 = %d>\n", fd4);
	printf("%s", get_next_line(fd4));

	printf("<3 charactors : fd3 = %d>\n", fd3);
	printf("%s", get_next_line(fd3));

	printf("<1 charactor : fd4 = %d>\n", fd4);
	printf("%s", get_next_line(fd4));

	close (fd1);
	close (fd2);
	close (fd3);
	close (fd4);
	close (fd5);
	close (fd6);

	return (0);
}
