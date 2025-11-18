/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:05:07 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/18 20:28:22 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

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


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1_new;
	char	*s2_new;
	char	*str;

	s1_new = (char *)s1;
	s2_new = (char *)s2;
	str = (char *)ft_calloc(ft_strlen(s2) + ft_strlen(s1) + 1, 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (ft_strlen(s1_new) + 1));
	ft_strlcat(str, s2, ft_strlen(s1_new) + ft_strlen(s2_new) + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (size <= 0)
		return (len_src);
	while ((i < size - 1) && (src[i]))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

