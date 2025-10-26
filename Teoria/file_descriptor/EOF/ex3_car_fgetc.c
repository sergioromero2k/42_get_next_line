#include <stdio.h>

int	main(void)
{
	FILE	*f;
	int		c;

	f = fopen("salida.txt", "r");
	if (!f)
		return (1);
	while ((c = fgetc(f)) != EOF)
	{
		putchar(c);
	}
	fclose(f);
	return (0);
}
