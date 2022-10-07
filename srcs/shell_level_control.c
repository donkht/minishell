/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_level_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:54:33 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 14:44:53 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_value(t_info	*info)
{
	t_env	*tmp;

	tmp = NULL;
	tmp = info->envp_list;
	while (tmp != NULL)
	{
		if (ft_strncmp("SHLVL", tmp->key, 5) == 0)
			return (tmp->val);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	set_env_value(t_info	*info, char *str)
{
	t_env	*tmp;

	tmp = NULL;
	tmp = info->envp_list;
	while (tmp != NULL)
	{
		if (ft_strncmp("SHLVL", tmp->key, 5) == 0)
		{	
			if (tmp->val != NULL)
				free(tmp->val);
			tmp->val = str;
			break ;
		}
		tmp = tmp->next;
	}
}

void	shlevel_increase(t_info	*info)
{
	int		shlvl;
	t_env	*env;
	char	*cur_value;
	char	*new_value;

	env = info->envp_list;
	cur_value = get_env_value(info);
	shlvl = ft_atoi(cur_value);
	new_value = NULL;
	new_value = ft_itoa(shlvl + 1);
	if (!new_value)
		malloc_error_exit(info);
	if (shlvl > -1)
		set_env_value(info, new_value);
}
