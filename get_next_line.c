/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:05:17 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/18 20:42:18 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_jump_line(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '\n')
			break ;
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char	chunk[BUFFER_SIZE];
	size_t	n_bytes_read;
	size_t	i;
	size_t	len;
	bool	salto_linea;
	char	*new_line;

	// int			len_linea;
	len = 0;
	salto_linea = false;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	new_line = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!new_line)
		return (NULL);
	while (!salto_linea && ((n_bytes_read = read(fd, chunk, BUFFER_SIZE)) > 0))
	{
		i = 0;
		while (i < n_bytes_read)
		{
			new_line[len++] = chunk[i];
			if (chunk[i] == '\n')
			{
				salto_linea = true;
				break ;
			}
			i++;
		}
	}
	// if (n_bytes_read < 0)
	// 	return (NULL);
	if (close(fd) == -1)
		return (NULL);
	return (new_line);
}
char	*read_one_line(char *line)
{
	size_t	i;
	char	*new_line;
	size_t	long_line;

	if (!line[0])
		return (NULL);
	i = 0;
	long_line = ft_strlen_jump_line(line);
	new_line = ft_calloc(long_line, 1);
	if (!new_line)
		return (NULL);
	while (!line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		new_line[i++] = '\0';
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
	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
}
