#include <stdio.h>

void	alternar_mensaje(void)
{
	static int	n = 0;

	if (n % 2 != 0)
	{
		printf("Encendido\n");
	}
	else
	{
		printf("Apagado\n");
	}
	n++;
}
int	main(void)
{
	alternar_mensaje();
	alternar_mensaje();
	alternar_mensaje();
	alternar_mensaje();
	alternar_mensaje();
	alternar_mensaje();
}