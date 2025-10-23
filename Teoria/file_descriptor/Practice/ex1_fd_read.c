#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	buffer[100];
	ssize_t	bytes_leidos;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	bytes_leidos = read(fd, buffer, sizeof(buffer));
	if (bytes_leidos == -1)
	{
		close(fd);
		return (1);
	}
	write(1, buffer, bytes_leidos);
	close(fd);
	return (0);
}
