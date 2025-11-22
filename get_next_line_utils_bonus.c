/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:05:07 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/22 21:16:52 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
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
		return (NULL);
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
	size_t	len_s;
	size_t	i;

	if (!s)
		return (NULL);
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
	copy_s[i] = '\0';
	return (copy_s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ptr = str;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (str);
}
