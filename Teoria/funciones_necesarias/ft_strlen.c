/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:33:43 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/29 20:10:59 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h> // Libreria de strlen
#include <unistd.h>

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
/* int	main(void)
{
	// ft_strlen
	printf("%ld\n", ft_strlen("Hola mundo"));
	printf("%ld\n", ft_strlen(""));
	printf("%ld\n", ft_strlen("123456789"));
	// printf("%ld\n", ft_strlen(NULL));
	// Fallo de segmentación. --> __nonnull ((1)) explicarle que es esto.
	// strlen
	printf("%ld\n", strlen("Hola mundo"));
	// printf("%ld\n", strlen(NULL));
	// Fallo de segmentación. --> __nonnull ((1)) explicarle que es esto.
} */
