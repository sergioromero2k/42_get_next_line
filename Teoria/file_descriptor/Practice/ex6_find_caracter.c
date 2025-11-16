#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

int	main(int argc, char **argv)
{
	int fd;
	ssize_t n_bytes;
	char arr[BUFFER_SIZE];

	fd = open(argv[1], O_RDONLY);
	while ((n_bytes = read(fd, arr, sizeof(arr))) > 0)
	{
		for (int i = 0; i < n_bytes; i++)
		{
			if (arr[i] == 'a')
			{
				printf("¡Carácter 'a' encontrado!\n");
			}
		}
		if (write(STDOUT_FILENO, arr, n_bytes) == -1)
		{
			perror("Error al escribir la salida estandár");
			break ;
		}
	}
}
