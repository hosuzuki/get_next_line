#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	*malloc_error(size_t size);
char	*get_next_line(int fd);

__attribute__((destructor))
  static void destructor() {
      system("leaks -q a.out");
 }

int	main(void)
{
	char	*result;
	int		fd;
	char	c;

	result = &c;
	fd = open("test.txt", O_RDONLY);
	while (result != NULL)
	{
		result = get_next_line(fd);
		printf("%s", result);
		free(result);
	}
	printf("\n");
	close(fd);
	return (0);
}
