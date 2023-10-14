#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

__attribute__((destructor))
  static void destructor() {
      system("leaks -q a.out");
 }

int main(int argc, char **argv)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
	int	fd5;
	int	fd6;
	
	char	*s1 = NULL;
	char	*s2 = NULL;
	char	*s3 = NULL;
	char	*s4 = NULL;
	char	*s5 = NULL;
	char	*s6 = NULL;
	char	*s7 = NULL;
	char	*s8 = NULL;
	char	*s9 = NULL;
	char	*s10 = NULL;
	char	*s11 = NULL;
	char	*s12 = NULL;
	char	*s13 = NULL;

	(void)fd1;
	(void)fd2;
	(void)fd3;
	(void)fd4;
	(void)fd5;
	(void)fd6;

	(void)*s1;
	(void)*s2;
	(void)*s3;
	(void)*s4;
	(void)*s5;
	(void)*s6;
	(void)*s7;
	(void)*s8;
	(void)*s9;
	(void)*s10;
	(void)*s11;
	(void)*s12;
	(void)*s13;
	
	if (argc > 1)
	{
		(void)argv[0];
		printf("<std input test>\n");
		printf("%s", get_next_line(0));
		return (0);
	}

	fd1 = open("sample/empty", O_RDONLY);
	printf("<empty: fd1 = %d>\n", fd1);
	s1 = get_next_line(fd1);
	if (!s1)
		printf("NULL\n\n");
	else 
		printf("%s\n\n", s1);
	free (s1);
	
	fd2 = open("sample/just_nl", O_RDONLY);
	printf("<only new line: fd2 = %d>\n", fd2);
	s2 = get_next_line(fd2);
	printf("%s\n", s2);
	free (s2);

	fd3 = open("sample/3chara", O_RDONLY);
	printf("<3 characters: fd3 = %d>\n", fd3);
	s3 = get_next_line(fd3);
	printf("%s\n", s3);
	free(s3);

	fd4 = open("sample/1chara", O_RDONLY);
	printf("<1 character: fd4 = %d>\n", fd4);
	s4 = get_next_line(fd4);
	printf("%s\n", s4);
	free(s4);

	fd5 = open("sample/longletter", O_RDONLY);
	printf("<long letter: fd5 = %d>\n", fd5);
	s5 = get_next_line(fd5);
	printf("%s\n", s5);
	free(s5);

	fd6 = open("sample/over2k", O_RDONLY);
	printf("<2k+ characters: fd6 = %d>\n", fd6);
	s6 = get_next_line(fd6);
	printf("%s\n", s6);
	free(s6);

	printf("<long letter: fd5 = %d>\n", fd5);
	s7 = get_next_line(fd5);
	printf("%s\n", s7);
	free(s7);

	printf("<empty: fd1 = %d>\n", fd1);
	s8 = get_next_line(fd1);
	if (!s8)
		printf("NULL\n\n");
	else 
		printf("%s\n\n", s8);
	free(s8);

	printf("<only new line: fd2 = %d>\n", fd2);
	s9 = get_next_line(fd2);
	printf("%s\n", s9);
	free(s9);

	printf("<3 characters: fd3 = %d>\n", fd3);
	s10 = get_next_line(fd3);
	printf("%s\n", s10);
	free(s10);

	printf("<1 character: fd4 = %d>\n", fd4);
	s11 = get_next_line(fd4);
	printf("%s", s11);
	free(s11);

	printf("<3 characters: fd3 = %d>\n", fd3);
	s12 = get_next_line(fd3);
	printf("%s\n", s12);
	free(s12);

	printf("<1 character: fd4 = %d>\n", fd4);
	s13 = get_next_line(fd4);
	printf("%s\n", s13);
	free(s13);

	close (fd1);
	close (fd2);
	close (fd3);
	close (fd4);
	close (fd5);
	close (fd6);

	// test to cause Segmentation Fault
	// printf("<passing 42 as fd>\n");
	// printf("%s\n", get_next_line(42));

	return (0);
}
