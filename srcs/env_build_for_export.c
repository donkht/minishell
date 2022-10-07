/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env_for_export.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:28:26 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/27 17:59:46 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_quotes_to_val(char **env_item, char *arr, t_env *envp_list)
{
	char	*tmp;
	char	*quoted;

	tmp = ft_strjoin("\"", envp_list->val);
	quoted = ft_strjoin(tmp, "\"");
	arr = ft_strjoin(*env_item, quoted);
	free(*env_item);
	free(tmp);
	free(quoted);
	*env_item = arr;
}

static char	**build_env_expo_cicle(int len, t_env *envp_list, char **env_exp)
{
	int		i;
	char	*arr;
	char	*tmp_declare;

	i = -1;
	while (++i < len)
	{
		env_exp[i] = ft_strdup(envp_list->key);
		if (envp_list->separator)
		{
			arr = ft_strjoin(env_exp[i], "=");
			free(env_exp[i]);
			env_exp[i] = arr;
		}
		if (envp_list->val)
			add_quotes_to_val(&env_exp[i], arr, envp_list);
		tmp_declare = ft_strjoin("declare -x ", env_exp[i]);
		free(env_exp[i]);
		env_exp[i] = tmp_declare;
		envp_list = envp_list->next;
	}
	env_exp[i] = NULL;
	return (env_exp);
}

char	**build_env_for_export(t_info *info)
{	
	int		len;
	t_env	*envp_list;
	char	**env_exp;

	env_exp = NULL;
	envp_list = info->envp_list;
	len = ft_count_envp(envp_list);
	env_exp = malloc(sizeof(char *) * (len + 1));
	if (!env_exp)
		malloc_error_exit(info);
	env_exp = build_env_expo_cicle(len, envp_list, env_exp);
	return (env_exp);
}
