/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_vars_uncover.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:10:52 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 15:55:39 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	doll_simbol_in_quotes(char **val, t_info *info)
{
	if (!ft_strcmp(*val, "\"$\""))
	{
		free(*val);
		*val = ft_strdup("$");
		if (!*val)
			malloc_error_exit(info);
		return (1);
	}
	return (0);
}

static bool	var_answer_stat(char **value, t_info *info)
{
	if (ft_strcmp(*value, "$?") == 0)
	{
		free(*value);
		*value = ft_itoa(info->exit_status);
		return (true);
	}
	return (false);
}

static void	str_parts_handling(t_parts *parts, \
char **value, int *i, t_info *info)
{
	parts->before = ft_substr(*value, 0, *i);
	parts->value = ft_substr(*value, *i, size_of_var(parts->ptr, i));
	if (ft_strchr(parts->value, '\''))
		act_variable_one_quote(parts, value, *i);
	else
		parts->after = ft_substr(*value, *i, (ft_strlen(*value) - *i));
	uncover_value(&parts->value, info);
}

static bool	check_doll_simb(char **value, int *i, t_parts *parts, t_info *info)
{
	if (!(*value) || var_answer_stat(value, info))
		return (false);
	parts->ptr = find_exp_var(*value, i);
	if (!(parts->ptr))
		return (false);
	return (true);
}

void	dollar_vars_uncover(char **value, t_info *info)
{
	t_parts	parts;
	char	*new_str;
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (!check_doll_simb(value, &i, &parts, info)
		|| doll_simbol_in_quotes(value, info))
		return ;
	str_parts_handling(&parts, value, &i, info);
	tmp = ft_strjoin(parts.before, parts.value);
	new_str = ft_strjoin(tmp, parts.after);
	free(tmp);
	free(*value);
	*value = new_str;
	free_struct_t_parts(&parts);
	dollar_vars_uncover(value, info);
}
