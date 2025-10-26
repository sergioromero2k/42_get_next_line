#include <stdio.h>

int	main(void)
{
	signed char	c;

	printf("Escribe algo (Ctrl+D para terminar):\n");
	while ((c = getchar()) != EOF)
	{
		putchar(c);
	}
	printf("\n¡Fin de la entrada!\n");
	return (0);
}

// ./a.out < test.bin
// printf "\xFF" > test.bin
