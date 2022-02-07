/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:25:58 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 22:25:59 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_counter(int n)
{
	int	count;
	int	minus;

	minus = 0;
	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		minus = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count + minus);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	len = my_counter(n);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (len-- > sign)
	{
		ret[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		ret[0] = '-';
	return (ret);
}
