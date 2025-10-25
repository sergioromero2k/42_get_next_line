#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int	main(int argc, char **argv)
{
	int fd_read;
	int fd_write;
	char str[BUFFER_SIZE];
	ssize_t n_bytes;

	if (argc != 3)
		return (EXIT_FAILURE);

	fd_read = open(argv[1], O_RDONLY);
	if (fd_read == -1)
		return (EXIT_FAILURE);

	fd_write = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_write == -1)
		return (EXIT_FAILURE);

	while ((n_bytes = read(fd_read, str, sizeof(str))) > 0)
	{
		if (write(fd_write, str, n_bytes) == -1)
		{
			perror("Error al escribir archivo");
			close(fd_read);
			close(fd_write);
			return (EXIT_FAILURE);
		}
	}
	if (n_bytes == -1)
	{
		perror("Error de lectura en el archivo de origen");
		close(fd_read);
		close(fd_write);
		return (EXIT_FAILURE);
	}
	if (close(fd_read) == -1)
	{
		perror("Error al cerrar el archivo de lectura");
		return (EXIT_FAILURE);
	}
	if (close(fd_write) == -1)
	{
		perror("Error al cerrar de escritura");
		return (EXIT_FAILURE);
	}
	return (0);
}