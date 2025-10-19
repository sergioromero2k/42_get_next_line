#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd_read;
	int fd_write;

	if (argc != 3)
		return 1;

	fd_read=open(argv[1],O_RDONLY);
	if (fd_read == -1)
		return 1;

	fd_write=open(argv[2],O_WRONLY | O_CREAT, 0664);
	if (fd_write == -1)
		return 1;


