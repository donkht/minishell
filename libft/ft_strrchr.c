/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:27:56 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 22:27:57 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;

	r = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			r = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (r);
}
