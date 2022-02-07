/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:26:25 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 22:26:26 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	expo(int x)
{
	int	ret;

	ret = 1;
	while (--x > 0)
		ret = ret * 10;
	return (ret);
}

static void	pr(int n, int size, int fd)
{
	int		tmp;
	char	print;

	while (size > 0)
	{
		tmp = n / expo(size);
		print = 48 + (char)tmp;
		write(fd, &print, 1);
		n = n - expo(size) * tmp;
		size--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		size;
	int		tmp;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	if (n < 0)
		n = -n;
	tmp = n;
	size = 0;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		size++;
	}
	pr(n, size, fd);
}
