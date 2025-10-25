#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (EXIT_FAILURE);
	while (*arr)
	{
		i++;
		arr++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*arr;

	arr = "Hola mundo con fd!";
	if (argc != 2)
		return (EXIT_FAILURE);
	// ssize_t bytes_leidos;
	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		perror("Ha pasado un error al crear el archivo");
		return (1);
	}
	if ((write(fd, arr, ft_strlen(arr))) == -1)
	{
		perror("Error al escribir en el archivo");
		close(fd);
		return (EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		perror("Error al cerrar el archivo");
		return (EXIT_FAILURE);
	}
	return (0);
}
