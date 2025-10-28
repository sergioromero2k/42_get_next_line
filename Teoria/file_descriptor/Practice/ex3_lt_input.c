#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int	main(void)
{
	ssize_t	n_bytes;
	char	buffer[BUFFER_SIZE];

	while ((n_bytes = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		write(1, buffer, n_bytes);
	}
	if (n_bytes == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
