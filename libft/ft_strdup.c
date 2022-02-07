/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:28:10 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 22:28:11 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = malloc(ft_strlen((char *)s1) + 1);
	if (s2 == NULL)
		return (0);
	while (i < ft_strlen((char *)s1))
	{
		*(s2 + i) = *(char *)(s1 + i);
		i++;
	}
	*(s2 + i) = 0;
	return (s2);
}
