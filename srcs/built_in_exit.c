/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:59:35 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/27 03:26:48 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_minishell(t_info *info)
{
	free_all_data(info);
	exit(info->exit_status);
}

static int	is_string_number(char *string)
{
	while (*string)
		if (!ft_isdigit(*string++))
			return (0);
	return (1);
}

static void	parse_first_arg(char *arg, t_info *info)
{
	if (!arg)
		return ;
	info->exit_status = ft_atoi(arg);
	if (is_string_number(arg))
		return ;
	error_out_status("exit", "numeric argument required.", 2, info);
	exit_minishell(info);
}

static int	get_argc(char **argv)
{
	int	argc;

	argc = 0;
	while (*(++argv))
		argc++;
	return (argc);
}

void	built_in_exit(char **cmd, t_info *info)
{
	int	arg_count;

	arg_count = get_argc(cmd);
	parse_first_arg(*(cmd + 1), info);
	if (arg_count > 1)
	{
		error_out_status("exit: ", "too many arguments.", 1, info);
		return ;
	}
	ft_putendl_fd("exit", 1);
	exit_minishell(info);
}
