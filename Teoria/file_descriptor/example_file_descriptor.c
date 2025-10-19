#include <fcntl.h> // Para abrir open
#include <stdio.h>
#include <unistd.h> // Para read(), write() y close()

int	main(void)
{
	int		fd;
	char	buffer[100];
	ssize_t	bytes_leidos;

	// Abrir el archivo en modo solo lectura
	fd = open("ejemplo.txt", O_RDONLY);
	if (fd == -1)
	{
		// Manejar el error sie el archivo no se pudo abrir
		perror("Error al abrir archivo de lectura");
		return (1);
	}
	// Leer 100 bytes del archivo al búfer
	bytes_leidos = read(fd, buffer, sizeof(buffer));
	if (bytes_leidos == -1)
	{
		// Manejar el erro de lectura
		perror("Error al abrir bytes de lectura");
		close(fd);
		return (1);
	}
	// Escribir los bytes leídos en la salida estándar (fd 1)
	write(1, buffer, bytes_leidos);
	// Cerrar el descriptor de archivo
	close(fd);
	return (0);
}
