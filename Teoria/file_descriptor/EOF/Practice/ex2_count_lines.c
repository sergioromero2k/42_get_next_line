#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 100

int	main(void)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	n_lineas;
	ssize_t	n_bytes;
	int		i;
	ssize_t	last_bytes;

	n_lineas = 0;
	while ((n_bytes = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		last_bytes = n_bytes;
		write(1, buffer, n_bytes);
		i = 0;
		while (i < n_bytes)
		{
			if (buffer[i] == '\n')
				n_lineas++;
			i++;
		}
	}
	if (last_bytes > 0 && buffer[last_bytes - 1] != '\n')
		n_lineas++;
	printf("Nº líneas: %ld\n", n_lineas);
	return (0);
}
