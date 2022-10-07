/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:16:46 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 15:07:30 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	strsize;

	if (!s1)
		return (NULL);
	strsize = ft_strlen(s1) + 1;
	str = (char *)malloc(sizeof(char) * strsize);
	if (str)
	{
		str = ft_memcpy(str, s1, strsize);
		return (str);
	}
	return (NULL);
}
