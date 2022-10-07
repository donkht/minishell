/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:22:50 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 20:16:34 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_cd_status(t_info *info, char *strerr, char *dir, int status)
{
	info->exit_status = status;
	ft_putstr_fd("cd: ", STD_ERR);
	ft_putstr_fd(dir, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	ft_putendl_fd(strerr, STD_ERR);
}

static void	change_dir_to_path(char *dir, t_info *info)
{
	char	*pwd;
	char	buffer[1024];

	pwd = getcwd(buffer, sizeof(buffer));
	if (find_env_key(info, "OLDPWD"))
		replace_env_val(info, "OLDPWD", pwd);
	else
		envp_add(info, "OLDPWD", pwd, '=');
	if (chdir(dir) != 0 && ft_strchr(dir, '>') == NULL)
	{
		error_cd_status(info, strerror(errno), dir, 1);
		return ;
	}
	pwd = getcwd(buffer, sizeof(buffer));
	if (find_env_key(info, "PWD"))
		replace_env_val(info, "PWD", pwd);
	else
		envp_add(info, "PWD", pwd, '=');
}

static void	go_to_oldpwd(char *path, t_info *info)
{
	ft_putendl_fd(path, 1);
	change_dir_to_path(path, info);
}

static void	go_to_home(t_info *info)
{
	char	*dir;
	char	*env_val;

	env_val = find_envair_value(info, "HOME");
	dir = ft_strdup(env_val);
	if (dir == NULL)
	{
		error_out_status("cd", "HOME not set.", 1, info);
		free(dir);
		return ;
	}
	change_dir_to_path(dir, info);
	free(dir);
}

void	built_in_cd(char *dir, t_info *info)
{
	char	*current_dir;

	current_dir = NULL;
	info->exit_status = 0;
	if ((!dir) || (!ft_strncmp(dir, "~", 1)))
	{
		go_to_home(info);
		return ;
	}
	else if (ft_strcmp(dir, "-") == 0)
	{
		current_dir = ft_strdup(find_envair_value(info, "OLDPWD"));
		if (current_dir == NULL)
		{
			error_out_status("cd", "OLDPWD not set.", 1, info);
			return ;
		}
		go_to_oldpwd(current_dir, info);
	}
	else
	{
		current_dir = ft_strdup(dir);
		change_dir_to_path(current_dir, info);
	}
	free(current_dir);
}
