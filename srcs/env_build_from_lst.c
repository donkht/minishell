/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_build_from_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:16:40 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 13:36:45 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_envp(t_env *envp_list)
{
	int	res;

	res = 0;
	while (envp_list)
	{
		res++;
		envp_list = envp_list->next;
	}
	return (res);
}

static void	build_env_cicle(t_info *info, int len, t_env *envp_list)
{
	int		i;
	char	*arr;

	i = -1;
	while (++i < len)
	{
		info->envp[i] = ft_strdup(envp_list->key);
		if (!info->envp[i])
			malloc_error_exit(info);
		if (envp_list->separator)
		{
			arr = ft_strjoin(info->envp[i], "=");
			free(info->envp[i]);
			info->envp[i] = arr;
		}
		if (envp_list->val)
		{
			arr = ft_strjoin(info->envp[i], envp_list->val);
			free(info->envp[i]);
			info->envp[i] = arr;
		}
		envp_list = envp_list->next;
	}
	info->envp[i] = NULL;
}

void	build_env_from_list(t_info *info, t_env *envp_list)
{	
	int		len;

	len = ft_count_envp(envp_list);
	info->envp = malloc(sizeof(char *) * (len + 1));
	if (!info->envp)
		malloc_error_exit(info);
	build_env_cicle(info, len, envp_list);
}
