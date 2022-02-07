/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:26:29 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/30 04:33:20 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != 0)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
			count++;
		s++;
	}
	return (count);
}

static char	*new_word_alloc(char const *s, char c)
{
	char	*ret;
	int		letters;
	char	*tmp;

	tmp = (char *)s;
	letters = 0;
	while (*tmp != c && *tmp != 0)
	{
		tmp++;
		letters++;
	}
	ret = malloc(letters + 1);
	if (!ret)
		return (NULL);
	ret[letters] = '\0';
	while (letters > 0)
	{
		letters--;
		ret[letters] = s[letters];
	}
	return (ret);
}

static void	free_navalny(char **ret, int i)
{
	while (--i > 0)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ret;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ret = malloc(sizeof(char *) * words + 1);
	if (!ret)
		return (NULL);
	ret[words] = NULL;
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		ret[i] = new_word_alloc(s, c);
		if (!ret[i])
			free_navalny(ret, i);
		while (*s != c)
			s++;
		i++;
	}
	return (ret);
}
