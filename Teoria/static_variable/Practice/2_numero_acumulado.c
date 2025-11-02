#include <stdio.h>

void	acumular(int n)
{
	static int	nm = 0;

	nm += n;
	printf("Número acumulado: %d\n", nm);
}
int	main(void)
{
	acumular(5);
	acumular(3);
	acumular(2);

	return (0);
}