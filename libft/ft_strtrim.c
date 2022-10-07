/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:31:08 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/08 21:24:06 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	trstr_len;
	char	*tr_str;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	trstr_len = ft_strlen(s1);
	while (trstr_len > begin && ft_strrchr(set, s1[trstr_len]))
		trstr_len--;
	tr_str = ft_substr(s1, begin, (trstr_len - begin) + 1);
	return (tr_str);
}
