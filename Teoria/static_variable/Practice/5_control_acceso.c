#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	acceso_correcto(void)
{
	static int	contador = 0;

	contador++;
	if (contador > 3)
		return (4);
	return (contador);
}
int	main(void)
{
	if (acceso_correcto() == 4)
	{
		printf("Acceso denegado");
	}
	else
	{
		printf("%d", acceso_correcto());
	}
}
