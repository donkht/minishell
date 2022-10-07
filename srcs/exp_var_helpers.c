/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_var_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:40:57 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 17:17:30 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_exp_var(char *value, int *i)
{
	while (value[*i] != '\0')
	{
		if (value[*i] == '$')
			return (&value[*i]);
		*i += 1;
	}
	return (NULL);
}

int	size_of_var(char *parts, int *index)
{
	int	i;

	i = 0;
	while ((parts[i + 1] != ' ') && (parts[i + 1] != '\0') \
	&& (parts[i + 1] != '$'))
		i++;
	i++;
	*index += i;
	return (i);
}

void	act_variable_one_quote(t_parts *parts, char **value, int i)
{
	char	**splited_string;
	char	*temp;
	char	*tmp2;

	splited_string = ft_split(parts->value, '\'');
	free_element((void **)&parts->value);
	parts->value = ft_strdup(splited_string[0]);
	if (splited_string[1])
		temp = ft_strjoin("\'", splited_string[1]);
	else
		temp = ft_strdup("\'");
	tmp2 = ft_substr(*value, i, (ft_strlen(*value) - i));
	parts->after = ft_strjoin(temp, tmp2);
	free_element((void **)temp);
	free_element((void **)tmp2);
	xx_arr_clean(splited_string);
}
