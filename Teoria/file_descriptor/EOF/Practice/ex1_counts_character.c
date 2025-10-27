#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int	main(void)
{
	char	arr[BUFFER_SIZE];
	ssize_t	n_bytes;
	ssize_t	total;

	total = 0;
	while ((n_bytes = read(0, arr, BUFFER_SIZE)) > 0)
	{
		write(1, arr, n_bytes);
		total += n_bytes;
		printf("Total: %ld\n", total);
		printf("\nN_bytes: %ld\n", n_bytes);
	}
	/* 	printf("\n--- Fin de lectura ---\n");
		printf("Total final: %ld\n", total);
		printf("Último n_bytes: %ld\n", n_bytes);
		fflush(stdout); // Fuerza el vaciado final del buffer */
	return (0);
}
