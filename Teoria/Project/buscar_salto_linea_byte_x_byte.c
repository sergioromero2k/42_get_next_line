#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024

int	main(int argc, char **argv)
{
	int		fd;
	char	c;
	ssize_t	n_bytes;
	char	line_buffer[MAX_LINE_SIZE];
	int		i;                                     

	i = 0;
	if (argc != 2)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	while ((n_bytes = read(fd, &c, 1)) > 0)
	{
		if (i >= MAX_LINE_SIZE - 1)
		{
			fprintf(stderr, "Error: Línea demasiado larga.\n");
			break ;
		}
		line_buffer[i++] = c;
		if (c == '\n')
		{
			break ;
		}
	}
	line_buffer[i] = '\0';
	if (write(STDOUT_FILENO, line_buffer, i) == -1)
	{
		perror("Error al escribir la salida estándar");
	}
	if (n_bytes == -1)
	{
		perror("Error de lectura con read");
	}
	close(fd);
	return (EXIT_SUCCESS);
}
