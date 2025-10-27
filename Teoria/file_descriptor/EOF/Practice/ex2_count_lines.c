#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 100

// Si lo hiciste asi, solo cuenta cuántas veces read() leyó algo.
// Cada vez que read() devuelve algo (puede ser una o varias líneas, o incluso una línea incompleta).
// Pero read() no garantiza leer justo hasta un \n — puede leer trozos arbitrarios de datos según el tamaño del búfer o cómo el sistema entregue la entrada.

int	main(void)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	n_lineas;
	ssize_t	n_bytes;

	n_lineas = 0;
	while ((n_bytes = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		write(1, buffer, n_bytes);
		n_lineas += 1;
	}
		printf("Nº líneas: %ld\n", n_lineas);
	return (0);
}
