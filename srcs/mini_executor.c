/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:47:46 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 20:29:11 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_path(t_info *info)
{
	t_env	*tmp;

	tmp = info->envp_list;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, "PATH") == 0)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

static char	*find_avalable_path(char **paths_all, \
char *path_cmd, char *cmd0, t_info *info)
{
	char	*path_pref;
	int		i;

	i = 0;
	while (paths_all && paths_all[i])
	{
		path_pref = ft_strjoin(paths_all[i], "/");
		if (!path_pref)
			malloc_error_exit(info);
		path_cmd = ft_strjoin(path_pref, cmd0);
		if (!path_cmd)
			malloc_error_exit(info);
		free(path_pref);
		if (access(path_cmd, F_OK) == 0)
		{
			xx_arr_clean(paths_all);
			return (path_cmd);
		}
		free(path_cmd);
		path_cmd = NULL;
		i++;
	}
	return (NULL);
}

char	*set_path_var(t_info *info, char *cmd0)
{
	t_env	*tmp;
	char	**paths_all;
	char	*path_cmd;

	path_cmd = NULL;
	if ((cmd0[0] == '.' && cmd0[1] == '/') || \
	(cmd0[0] == '.' && cmd0[1] == '.' && cmd0[2] == '/') || cmd0[0] == '/')
	{
		if (access(cmd0, F_OK) == 0)
			return (cmd0);
		else
			return (NULL);
	}
	tmp = info->envp_list;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, "PATH") == 0)
			break ;
		tmp = tmp->next;
	}
	paths_all = ft_split(tmp->val, ':');
	if (!paths_all)
		malloc_error_exit(info);
	path_cmd = find_avalable_path(paths_all, path_cmd, cmd0, info);
	return (path_cmd);
}

static void	run_command(t_info *info, char **cmd)
{
	int		pid;
	int		status;

	info->exit_status = 0;
	if ((!cmd[0]) || (!check_path(info)))
		return ;
	info->path = set_path_var(info, cmd[0]);
	if (!info->path || (!check_exec(info->path)))
	{
		error_out_status(cmd[0], "Command not found", 127, info);
		return ;
	}
	pid = fork();
	signals_for_child();
	if (pid == 0)
	{
		build_env_from_list(info, info->envp_list);
		execve(info->path, cmd, info->envp);
		xx_arr_clean(info->envp);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		info->exit_status = WEXITSTATUS(status);
}

/* selecting the type of program to run */
void	executor_select(t_info *info, char **cmd)
{
	if (cmd[0] != NULL && builtin_check(cmd[0]))
		run_built_ins(&cmd[0], info);
	else
		run_command(info, &cmd[0]);
}
