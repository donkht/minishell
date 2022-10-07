/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:05:12 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:23:00 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{	
	unsigned char	*string;
	size_t			i;

	string = (unsigned char *)b;
	i = 0;
	while (i < len)
	{	
		string[i] = c;
		i++;
	}
	return (b);
}
