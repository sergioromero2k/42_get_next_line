/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:11:22 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/29 21:01:21 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
/* int	main(void)
{
	printf("%p\n", ft_strchr("hola mundo", 'h'));
	printf("%p\n", ft_strchr("hola mundo", 'o'));
	printf("%p\n", ft_strchr("hola mundz", 'z'));
	printf("%p\n", ft_strchr("hola mundz", '\0'));
	printf("%p\n", ft_strchr("hola mundo", 'm' + 256));
	printf("%p\n", ft_strchr("hola mundo", 2));
	printf("%p\n", ft_strchr(NULL, 'e')); // Debe darte segmentación fault
}
 */