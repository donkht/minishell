/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:30:43 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:24:10 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	slen;
	size_t	subsize;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup("\0"));
	subsize = ft_strlen(s + start);
	if (subsize < len)
		len = subsize;
	sstr = (char *)malloc(sizeof(char) * len + 1);
	if (!sstr)
		return (NULL);
	ft_memmove(sstr, (s + start), len);
	sstr[len] = '\0';
	return (sstr);
}
