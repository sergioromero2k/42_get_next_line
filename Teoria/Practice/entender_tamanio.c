#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char	c;
	char	*str;
	int		len;
	char	*temp;
	int		i;
	ssize_t	bytes_read;

	str = NULL;
	len = 0;
	while ((bytes_read = read(0, &c, 1)) > 0)
	{
		temp = malloc(len + 2);
		i = 0;
		while (i < len)
		{
			temp[i] = str[i];
			i++;
		}
		temp[len] = c;
		temp[len + 1] = '\0';
		free(str);
		str = temp;
		len++;
	}
	if (bytes_read == 0 && len == 0)
	{
		printf("\nFin del archivo (Ctrl + D detectado)\n");
		return (0);
	}
	printf("%s\n", str);
	free(str);
}
