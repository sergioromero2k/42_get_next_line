#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int	main(void)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	n_bytes;
	int		i;
	ssize_t	n_words;

	n_words = 0;
	while ((n_bytes = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		write(1, buffer, n_bytes);
		i = 0;
		while (i < n_bytes)
		{
			if (buffer[i] == 9 || buffer[i] == 32 || buffer[i] == '\n')
				n_words++;
			i++;
		}
	}
	printf("El numero de palabras son %lu", n_words);
	return (0);
}
