/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:58:14 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:21:16 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*resptr;
	size_t	fullsize;

	fullsize = (size * count);
	resptr = (void *)malloc(fullsize);
	if (!resptr)
		return (NULL);
	ft_bzero(resptr, fullsize);
	return (resptr);
}
