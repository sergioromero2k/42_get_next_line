#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int	main(int argc, char **argv)
{
	int		fd;
	char	arr[BUFFER_SIZE];
	ssize_t	n_bytes;

	if (argc != 2)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	while ((n_bytes = read(fd, arr, sizeof(arr))) > 0)
	{
		if (write(STDOUT_FILENO, arr, n_bytes) == -1)
		{
			perror("Error al escribir la salida estandár");
			break ;
		}
	}
	if (n_bytes == -1)
	{
		// Esto indica un error de lectura de disco u otro problema
		perror("Error de lectura con read");
	}
	if (close(fd) == -1)
	{
		perror("Erro al cerrar el archivo");
		return (EXIT_FAILURE);
	}
}
