/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:45:14 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:22:43 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	size_t			i;

	string = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (string[i] == (unsigned char)c)
			return ((unsigned char *)string + i);
		i++;
	}
	return (NULL);
}
