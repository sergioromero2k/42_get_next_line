#include <unistd.h>	// Para open, read, close
#include <fcntl.h>	// Para las banderas (O_RDONLY)
#include <stdlib.h>	// Para EXIT_FAILURE
#include <stdio.h>	// Para perror

int main(int argc, char **argv)
{
	int fd;
	ssize_t n_bytes;
	char buffer[1024];	// Búfer para almacenar los datos leídos

	if (argc == 2)
		return 1;

	fd=open(argv[1],O_RDONLY);

	if(fd==-1)
		return EXIT_FAILURE;

	while((n_bytes=read(fd,buffer,sizeof(buffer))>0))
	{
		if(write(STDOUT_FILENO, buffer, n_bytes) == -1)
		{
			perror("Error al escribir a la salida estándar");
			break;
		}
	}

	// Comprobar final y cerrar el archivo
	if(n_bytes == -1){
		// Esto indica un error de lectura de disco u otro problema
		perror("Error de lectura con read");}

	if(close(fd)==-1)
	{
		perror("Error al cerrar el archivo con close");
		return EXIT_FAILURE;
	}
	return 0;
}
