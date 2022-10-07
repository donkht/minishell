/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:00:19 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 20:20:50 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_check(char *content)
{
	if (!(ft_strcmp(content, "echo")) \
	|| !(ft_strcmp(content, "cd")) \
	|| !(ft_strcmp(content, "pwd")) \
	|| !(ft_strcmp(content, "export")) \
	|| !(ft_strcmp(content, "unset")) \
	|| !(ft_strcmp(content, "env")) \
	|| !(ft_strcmp(content, "exit")))
		return (1);
	else
		return (0);
}

void	run_built_ins(char **cmd, t_info *info)
{
	if (!(ft_strcmp(cmd[0], "echo")))
		built_in_echo(cmd, info);
	else if (!(ft_strcmp(cmd[0], "pwd")))
		built_in_pwd(info);
	else if (!(ft_strcmp(cmd[0], "cd")))
		built_in_cd(cmd[1], info);
	else if (!(ft_strcmp(cmd[0], "export")))
		built_in_export(cmd, info);
	else if (!(ft_strcmp(cmd[0], "unset")))
		built_in_unset(cmd, info);
	else if (!(ft_strcmp(cmd[0], "env")))
		built_in_env(info);
	else if (!(ft_strcmp(cmd[0], "exit")))
		built_in_exit(cmd, info);
}
