/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:33:48 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:23:30 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	s1size;
	size_t	s2size;
	size_t	newsize;

	if (!s1 || !s2)
		return (NULL);
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	newsize = (s1size + s2size + 1);
	newstr = (char *)malloc(sizeof(char) * newsize);
	if (!newstr)
		return (NULL);
	ft_memmove(newstr, s1, s1size);
	ft_memmove(newstr + s1size, s2, s2size);
	newstr[newsize - 1] = '\0';
	return (newstr);
}
