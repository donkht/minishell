/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_uncover_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:33:00 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 15:41:26 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	recover_quote(int quote_flag, char **value, char **temp)
{
	if (quote_flag == 1)
	{
		*temp = ft_strjoin(*value, "\"");
		free(*value);
		*value = ft_strdup(*temp);
		free(*temp);
	}
}

void	uncover_value(char **doll_var, t_info *info)
{
	int		quote_flag;
	char	*val;
	char	*key;
	char	*tmp;

	quote_flag = 0;
	tmp = *doll_var;
	tmp++;
	if (ft_strchr(tmp, '\"'))
	{
		key = ft_strtrim(tmp, "\"");
		quote_flag = 1;
	}
	else
		key = ft_strdup(tmp);
	val = ft_strdup(find_envair_value(info, key));
	if (!val)
		val = ft_strdup("");
	free(*doll_var);
	free(key);
	recover_quote(quote_flag, &val, &tmp);
	*doll_var = val;
}
