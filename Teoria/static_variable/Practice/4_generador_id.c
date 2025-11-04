#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	nuevo_id(void)
{
	static int	contador = 0;

	contador += 1;
	return (contador);
}
int	main(void)
{
	printf("%d\n", nuevo_id());
	printf("%d\n", nuevo_id());
	printf("%d\n", nuevo_id());
}
