/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:32:16 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 11:40:16 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_error(t_info *info, char *var)
{
	info->exit_status = 1;
	ft_putstr_fd("unset: `", 2);
	ft_putstr_fd(var, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

bool	if_unset_error(t_info *info, char *str)
{
	if ((!ft_isalpha(str[0]) && str[0] != '_') \
	|| (str[0] == '_' && str[1] == '\0'))
	{
		unset_error(info, str);
		return (true);
	}
	return (false);
}

void	delete_env(t_env *env, t_env *root)
{
	t_env	*tmp;

	tmp = root;
	while (tmp->next != env)
	{
	tmp = tmp->next;
	}
	tmp->next = env->next;
	free(env->key);
	free(env->val);
	free(env);
}

int	check_n_del_root(t_env **env, char *str)
{
	t_env	*tmp;

	tmp = *env;
	if (!ft_strcmp(str, tmp->key))
	{
		*env = (*env)->next;
		free(tmp->key);
		free(tmp->val);
		free(tmp);
		return (1);
	}
	return (0);
}

void	built_in_unset(char **cmd, t_info *info)
{
	int		i;
	t_env	*env_to_del;
	t_env	*root;

	root = info->envp_list;
	if (!root)
		return ;
	i = 1;
	info->exit_status = 0;
	while (cmd[i])
	{
		if (if_unset_error(info, cmd[i]))
			return ;
		if (find_env_key(info, cmd[i]))
		{
			if (check_n_del_root(&info->envp_list, cmd[i]))
				continue ;
			env_to_del = env_list_search(info, cmd[i]);
			delete_env(env_to_del, root);
		}
		i++;
	}
}
