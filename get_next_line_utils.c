/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:05:07 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/19 22:13:24 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
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

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (free(s), s = NULL, NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*copy_s;
	int		len_s;
	size_t	i;

	if (!s)
		return (free(s), s = NULL, NULL);
	i = 0;
	len_s = ft_strlen(s);
	copy_s = malloc(len_s + 1);
	if (!copy_s)
		return (NULL);
	while (s[i])
	{
		copy_s[i] = s[i];
		i++;
	}
	return (copy_s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		return (free(s1), s1 = NULL, NULL);
	str = (char *)malloc(ft_strlen(s2) + ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (ft_strlen(s1) + 1));
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
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
size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
