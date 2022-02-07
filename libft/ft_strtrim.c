/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:27:57 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 22:27:59 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	len;

	if (!s1)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != 0)
		s1++;
	len = ft_strlen((char *)s1);
	while (ft_strchr(set, *(s1 + len - 1)) && len > 1)
		len--;
	ret = ft_substr(s1, 0, len);
	return (ret);
}
