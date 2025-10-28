#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int	main(int argc, char **argv)
{
	int		fd;
	ssize_t	n_bytes;
	char	buffer[BUFFER_SIZE];

	if (argc != 2)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_CREAT);
	if (fd == -1)
	{
		perror("Error al crear el file descriptor");
		return (EXIT_FAILURE);
	}
	while ((n_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
		write(1, buffer, n_bytes);
	if (n_bytes == -1)
	{
		perror("Error en el nº de bytes");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
