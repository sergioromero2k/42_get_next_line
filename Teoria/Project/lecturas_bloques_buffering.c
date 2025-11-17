#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CHUNK_SIZE 1024
#define MAX_LINE_LEN 4096

void	read_one_line(int fd)
{
	char	chunk_buffer[CHUNK_SIZE];
	char	final_line[MAX_LINE_LEN];
	ssize_t	n_read;
	int		line_pos;
	int		i;

	line_pos = 0;
	while ((n_read = read(fd, chunk_buffer, CHUNK_SIZE)) > 0)
	{
		i = 0;
		while (i < n_read)
		{
			final_line[line_pos++] = chunk_buffer[i];
			if (chunk_buffer[i] == '\n')
			{
				goto line_finished;
			}
			if (line_pos >= MAX_LINE_LEN - 1)
			{
				fprintf(stderr, "Error: Línea demasiado larga.\n");
				goto line_finished;
			}
			i++;
		}
	}
line_finished:;
	if (line_pos > 0)
	{
		final_line[line_pos] = '\0';
		printf("Línea leída: %s", final_line);
	}
	else if (n_read == -1)
	{
		perror("Error de lectura con read");
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);

	read_one_line(fd);

	close(fd);
	return (EXIT_SUCCESS);
}