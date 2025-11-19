/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:05:07 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/19 21:15:15 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > (SIZE_MAX / nmemb))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*pr;

	pr = (unsigned char *)s;
	while (n--)
		*pr++ = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return (str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*join;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = ft_calloc(len + 1, 1);
	if (!join)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	free(s1);
	return (join);
}

char	*ft_strdup(const char *s)
{
	char *copy_s;
	int len_s;
	size_t i;

	i = 0;
	len_s = ft_strlen(s);
	copy_s = ft_calloc(len_s + 1, (sizeof(char)));
	if (!copy_s)
		return (NULL);
	while (s[i])
	{
		copy_s[i] = s[i];
		i++;
	}
	return (copy_s);
}