/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:05:17 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/16 18:51:09 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*arr;
	ssize_t	n_bytes;

	if (fd < 0)
		return (NULL);
	arr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!arr)
		return (free(arr), NULL);
	while ((n_bytes = read(fd, arr, sizeof(arr))) > 0)
	{
		if (write(STDOUT_FILENO, arr, n_bytes) == -1)
			return (free(arr), NULL);
	}
	if (n_bytes == -1)
		return (free(arr), NULL);
	if (close(fd) == -1)
		return (NULL);

}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	get_next_line(fd);
}
