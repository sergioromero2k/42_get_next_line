#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	arr[100];
	ssize_t	n_bytes;

	while ((n_bytes = read(0, arr, sizeof(arr))) > 0)
	{
		write(1, arr, n_bytes);
	}
}
