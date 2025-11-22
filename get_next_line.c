/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:05:17 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/22 21:41:27 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_until_jump_line(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*read_one_line(char *line)
{
	size_t	i;
	char	*new_line;
	size_t	long_line;

	long_line = ft_strlen_until_jump_line(line);
	if (long_line == 0)
		return (NULL);
	new_line = malloc(long_line + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < long_line)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*read_file_descriptor(int fd, char *text)
{
	char	*buf;
	ssize_t	n_read;
	char	*tmp;

	text = verify_assigned(text);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf || !text)
		return (free(buf), free(text), NULL);
	n_read = 1;
	while (!ft_strchr(text, '\n') && n_read > 0)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read < 0)
			return (free(buf), free(text), NULL);
		buf[n_read] = '\0';
		tmp = text;
		text = ft_strjoin(tmp, buf);
		free(tmp);
		if (!text)
			return (free(buf), NULL);
	}
	free(buf);
	return (text);
}

char	*verify_assigned(char *text)
{
	if (!text)
	{
		text = malloc(1);
		if (!text)
			return (NULL);
		text[0] = '\0';
	}
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;
	char		*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = read_file_descriptor(fd, text);
	if (!text)
		return (NULL);
	line = read_one_line(text);
	if (!line)
		return (free(text), text = NULL, (NULL));
	rest = ft_strdup(text + ft_strlen_until_jump_line(text));
	free(text);
	if (!rest || !*rest)
	{
		free(rest);
		text = NULL;
	}
	else
		text = rest;
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	int	fd;

// 	if (argc != 2)
// 		return (EXIT_FAILURE);
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 		return (EXIT_FAILURE);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// }
