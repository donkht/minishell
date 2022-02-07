/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:27:42 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 22:27:43 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen((char *)src);
	i = 0;
	if (lendst + 1 < dstsize)
	{
		while (lendst + i < dstsize - 1)
		{
			dst[lendst + i] = src[i];
			if (src[i] == 0)
				return (lendst + lensrc);
			i++;
		}
		dst[lendst + i] = 0;
	}
	if (lendst > dstsize)
		lendst = dstsize;
	return (lendst + lensrc);
}
