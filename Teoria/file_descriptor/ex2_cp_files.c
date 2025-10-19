#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

# define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
	int 	fd_read;
	int 	fd_write;
	char	str[BUFFER_SIZE];

	if (argc != 3)
		return EXIT_FAILURE;

	fd_read=open(argv[1],O_RDONLY);
	if (fd_read == -1)
		return EXIT_FAILURE;

	fd_write=open(argv[2],O_WRONLY | O_CREAT, 0664);
	if (fd_write == -1)
		return EXIT_FAILURE;

	while((n_bytes=read(fd,str,sizeof(str)))>0)
	{
		if(write(fd_write,str,n_bytes)==-1)
		{
			perror();
		}
	}


