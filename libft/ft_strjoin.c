/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:26:38 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 22:26:39 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (0);
	while (*s1 != 0)
		*p++ = *s1++;
	while (*s2 != 0)
		*p++ = *s2++;
	*p = 0;
	return (p - i);
}
