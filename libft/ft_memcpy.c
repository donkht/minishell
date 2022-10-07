/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:31:42 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:22:52 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dst);
}
