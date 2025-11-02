#include <stdio.h>

void	contador(void)
{
	static int	contador = 0;

	// No puedes poner la inicialización de una variable static separada de su declaración dentro de la función, es decir van juntos.
	contador++;
	printf("%d\n", contador);
}

int	main(void)
{
	contador();
	contador();
	contador();
	contador();
	contador();
	contador();
	return (0);
}
