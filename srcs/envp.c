/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:05:41 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 20:27:06 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_envair_value(t_info *info, char *key)
{
	t_env	*tmp;

	tmp = info->envp_list;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp->val);
		tmp = tmp->next;
	}
	return (NULL);
}

static t_env	*new_env(char *key, char *val, int separator)
{
	t_env	*env;

	env = NULL;
	env = ft_calloc(1, sizeof(t_env));
	if (env)
	{
		env->key = ft_strdup(key);
		env->separator = separator;
		env->next = NULL;
		if (val)
			env->val = ft_strdup(val);
		else
			env->val = ft_strdup("");
	}
	else
		exit(1);
	return (env);
}

void	envp_add(t_info *info, char *key, char *val, int separator)
{
	t_env	*env;

	if (info->envp_list == NULL)
		info->envp_list = new_env(key, val, separator);
	else
	{
		env = info->envp_list;
		while (env->next)
			env = env->next;
		env->next = new_env(key, val, separator);
	}
}

static void	key_val_free(char *key, char *val)
{
	if (key)
		free(key);
	if (val)
		free(val);
}

void	envp_to_list(t_info *info, char **envp)
{
	char	*key;
	char	*val;
	int		i;
	int		j;

	key = NULL;
	val = NULL;
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][j] == '=')
			{
				key = ft_substr(envp[i], 0, j);
				val = ft_substr(envp[i], j + 1, ft_strlen(envp[i]) - j - 1);
				break ;
			}
			j++;
		}
		envp_add(info, key, val, 61);
		key_val_free(key, val);
		i++;
	}
}
