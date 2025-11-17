/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:05:17 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/17 21:56:20 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*chunk;
	ssize_t		n_bytes;
	// int			len_linea;
	size_t		i;
	size_t		salto_linea;
	char		*new_line;

	salto_linea = 1;
	if (fd < 0)
		return (NULL);
	chunk = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!chunk)
		return (free(chunk), NULL);
	new_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (salto_linea && ((n_bytes = read(fd, chunk, BUFFER_SIZE)) > 0))
	{
		i = 0;
		if (chunk[i] != '\n')
			salto_linea = 0;
		new_line[i] = chunk[i];
		i++;
	}
	if (n_bytes == -1)
		return (free(chunk), NULL);
	if (close(fd) == -1)
		return (NULL);
	return (new_line);
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
