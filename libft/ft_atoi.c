/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:20:55 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:21:03 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	long_max_detect(unsigned long number, int sign)
{
	if (number > LONG_MAX)
	{
		if (sign == -1)
			number = 0;
		else
			number = LONG_MAX;
	}	
	return (number);
}

int	ft_atoi(const char *str)
{
	unsigned long	number;
	int				sign;
	int				i;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f'
		|| str[i] == ' ' )
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit((int)str[i]))
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	number = long_max_detect(number, sign);
	return (number * sign);
}
