#include <stdio.h>

int main(void)
{
	char palabra[50];

	printf("Escribe palabras (Ctrl+D para terminar):\n");

	while(scanf("%49s",palabra) != EOF) 
	{
		printf("Leiste: %s\n",palabra);
	}
	printf("¡Fin de la entrada!\n");
	return 0;
}
