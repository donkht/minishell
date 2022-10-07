/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:35:16 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:21:41 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_size_intstr(int n)
{
	size_t	i;
	int		sign;

	if (n <= 0)
		sign = 1;
	else
		sign = 0;
	i = sign;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_strbuild(int n, char	*numstr, size_t	sizestr)
{
	numstr[sizestr] = '\0';
	if (n < 0)
	{
		numstr[0] = '-';
		n = -n;
	}
	else if (n == 0)
		numstr[0] = '0';
	while (n != 0)
	{	
		numstr[--sizestr] = (n % 10) + '0';
		n /= 10;
	}
	return (numstr);
}

char	*ft_itoa(int n)
{
	char	*numstr;
	size_t	sizestr;

	if (n == -2147483648)
	{
		numstr = ft_strdup("-2147483648");
		return (numstr);
	}
	sizestr = ft_size_intstr(n);
	numstr = (char *)ft_calloc((sizestr + 1), 1);
	if (numstr)
	{
		numstr = ft_strbuild(n, numstr, sizestr);
		return (numstr);
	}
	return (NULL);
}
