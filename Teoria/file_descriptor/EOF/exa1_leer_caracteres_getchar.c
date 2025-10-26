#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	c;

	printf("Escribe algo(CTRL+D)\n");
	while ((c = getchar()) != EOF)
	{
		putchar(c);
	}
	printf("\n¡Fin de la entrada!\n");
	return (0);
}
