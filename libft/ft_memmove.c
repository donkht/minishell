/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 23:10:26 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:22:56 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*strsrc;
	unsigned char	*strdst;
	size_t			i;

	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (strdst == strsrc)
		return (dst);
	while (i < len)
	{
		if (strdst > strsrc)
		{
			strdst[len - i - 1] = strsrc[len - i - 1];
		}
		else
		{
			strdst[i] = strsrc[i];
		}
		i++;
	}	
	return (dst);
}
