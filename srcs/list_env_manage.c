/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env_manage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:06:16 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 14:41:40 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_list_search(t_info *info, char *key)
{
	t_env	*tmp;

	tmp = info->envp_list;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	env_lst_delone(t_env *env, void (*del)(void*))
{
	t_env	*tmp;

	tmp = env->next;
	env->next = tmp->next;
	if (env && del)
	{	
		del(env->key);
		del(env->val);
		free(env);
		env = NULL;
	}
}

bool	find_env_key(t_info	*info, char *key)
{
	t_env	*tmp;

	tmp = NULL;
	tmp = info->envp_list;
	while (tmp != NULL)
	{
		if (ft_strcmp(key, tmp->key) == 0)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	replace_env_val(t_info	*info, char *key, char *new_val)
{
	t_env	*tmp;
	char	*place_val;

	place_val = NULL;
	tmp = NULL;
	tmp = info->envp_list;
	place_val = ft_strdup(new_val);
	if (!place_val)
		malloc_error_exit(info);
	while (tmp != NULL)
	{
		if (ft_strcmp(key, tmp->key) == 0)
			break ;
		tmp = tmp->next;
	}
	if (tmp->val)
		free(tmp->val);
	tmp->val = NULL;
	tmp->val = place_val;
}
