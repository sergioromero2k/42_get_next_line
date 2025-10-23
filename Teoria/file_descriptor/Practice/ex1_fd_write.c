#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *arr)
{
	int	i;

	i = 0;
	while (!arr)
	{
		i++;
		arr++;
	}
	return (i);
}

int	main(void)
{
	int		fd;
	char	*arr;

	arr = "Hola, mundo con fd!";
	// ssize_t bytes_leidos;
	fd = open("salida.txt", O_WRONLY | O_CREAT, 0664);
	if (fd == -1)
	{
		perror("Ha pasado un error al crear el archivo");
		return (1);
	}
	write(fd, arr, ft_strlen(arr));
	close(fd);
	return (0);
}
