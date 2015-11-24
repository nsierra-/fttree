#include <unistd.h>
#include <stdlib.h>
#include "private/misc.h"

void		*safe_malloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
	{
		write(1, "Malloc failed. Exit.\n", 21);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
