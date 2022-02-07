/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:27:47 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 22:27:48 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	if (dstsize < 1)
		return (ft_strlen((char *)src));
	while (i < dstsize - 1)
	{
		dst[i] = src[i];
		if (src[i] == 0)
			return (ft_strlen((char *)src));
		i++;
	}
	dst[i] = 0;
	return (ft_strlen((char *)src));
}
