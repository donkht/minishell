/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:30:43 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 13:32:06 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env_export(t_info *info)
{
	char	**env_quoted;

	env_quoted = build_env_for_export(info);
	print_env_array(env_quoted);
	xx_arr_clean(env_quoted);
}

static void	var_spliting(char **cmd, int i, t_info *info)
{
	char	**env_var;

	env_var = ft_split(cmd[i], '=');
	if (find_env_key(info, env_var[0]))
		replace_env_val(info, env_var[0], env_var[1]);
	else
		envp_add(info, env_var[0], env_var[1], '=');
	xx_arr_clean(env_var);
}

static void	update_var(char **cmd, int i, t_info *info)
{
	char	*val;	

	if (find_env_key(info, cmd[i]))
		return ;
	val = ft_strdup("");
	if (!val)
		malloc_error_exit(info);
	envp_add(info, cmd[i], val, '=');
	free(val);
}

static int	env_export_var_recu(char **cmd, int i, t_info *info)
{
	if (!cmd[i] || if_export_error(info, cmd[i]))
		return (0);
	if (ft_strchr(cmd[i], '='))
		var_spliting(cmd, i, info);
	else
		update_var(cmd, i, info);
	return (env_export_var_recu(cmd, i + 1, info));
}

int	built_in_export(char **cmd, t_info *info)
{
	info->exit_status = 0;
	if (cmd[1])
		return (env_export_var_recu(cmd, 1, info));
	else
		print_env_export(info);
	return (0);
}
