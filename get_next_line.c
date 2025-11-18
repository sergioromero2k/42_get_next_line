/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:05:17 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/18 21:37:47 by sergio-alej      ###   ########.fr       */
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

char	*read_one_line(char *line)
{
	size_t	i;
	char	*new_line;
	size_t	long_line;

	if (!line[0])
		return (NULL);
	i = 0;
	long_line = ft_strlen_jump_line(line);
	new_line = ft_calloc(long_line + 1, 1);
	if (!new_line)
		return (NULL);
	while (!line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	return (new_line);
}
char	*read_file_descriptor(int fd, char *text)
{
	char	*new_text;
	size_t	n_bytes_read;

	new_text = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!new_text)
		return (free(text), text = NULL, NULL);
	n_bytes_read = 1;
	while (n_bytes_read > 0 && !ft_strchr(text, '\n'))
	{
		n_bytes_read = read(fd, new_text, BUFFER_SIZE);
		if (n_bytes_read > 0)
		{
			new_text[n_bytes_read] = '\0';
			text = ft_strjoin(text, new_text);
		}
	}
	free(new_text);
	if (n_bytes_read <= 0)
		return (free(text), text = NULL, NULL);
	return (text);
}
char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	text = NULL;
	text = read_file_descriptor(fd, text);
	if (text)
		return (text = NULL, NULL);
	line = read_one_line(text);
	if (line)
		return (line = NULL, NULL);
	return (line);
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
