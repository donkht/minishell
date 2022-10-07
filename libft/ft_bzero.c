/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:01:27 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:21:10 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*string;
	size_t			i;

	string = (unsigned char *)s;
	i = 0;
	while (i < n)
	{	
		string[i] = '\0';
		i++;
	}
	s = string;
}
