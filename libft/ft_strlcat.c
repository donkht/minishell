/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:04:38 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:23:34 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	dstfsize;
	size_t	fullsize;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	srcsize = ft_strlen(src);
	dstfsize = ft_strlen(dst);
	fullsize = srcsize + dstfsize;
	if (dstsize <= dstfsize)
		return (srcsize + dstsize);
	while (dst[j] && j < dstsize)
		j++;
	while ((src[i] != '\0') && (i < dstsize - dstfsize - 1))
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (fullsize);
}
