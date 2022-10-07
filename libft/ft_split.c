/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:34:14 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/22 04:52:23 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_counter(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	nextstr;

	i = 0;
	count = 0;
	nextstr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && nextstr == 1)
			nextstr = 0;
		if (s[i] != c && nextstr == 0)
		{
			nextstr = 1;
			count++;
		}	
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	count;
	char	*start;

	if (!s)
		return (NULL);
	count = ft_str_counter((char *)s, c);
	list = (char **)malloc(sizeof(char *) * (count + 1));
	if (!list)
		return (NULL);
	start = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(list++) = ft_substr(start, 0, s - start);
			start = (char *)s + 1;
		}
		++s;
	}
	if (start != s)
		*(list++) = ft_substr(start, 0, s - start);
	*list = NULL;
	return (list - count);
}
