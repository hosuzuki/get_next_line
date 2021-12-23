#include <stdio.h>
#include <stdlib.h>

void	*malloc_error(size_t size)
{
	static int i;
	char *result;

	if (++i != NULL_TURN)
	{
		printf("i = %d : NULL_TURN : %d\n", i, NULL_TURN);
		result = malloc(size);
		return (result);
	}
	else
	{
		printf("\x1b[36mMALLOC_ERROR!!!\x1b[0m\n");
		i = 0;
		return (NULL);
	}
}

