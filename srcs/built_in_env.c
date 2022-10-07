/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 02:46:17 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 20:18:24 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_env_path_key(t_info	*info)
{
	t_env	*tmp;

	tmp = NULL;
	tmp = info->envp_list;
	while (tmp != NULL)
	{
		if (ft_strncmp("PATH", tmp->key, 4) == 0)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	print_env_array(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_putendl_fd(envp[i], 1);
		i++;
	}
}

void	built_in_env(t_info *info)
{
	if (!check_env_path_key(info))
		error_out_status("env: ", "No such file or directory", 127, info);
	info->exit_status = 0;
	build_env_from_list(info, info->envp_list);
	print_env_array(info->envp);
	xx_arr_clean(info->envp);
}
