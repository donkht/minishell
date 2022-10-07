/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:12:25 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 22:19:04 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in_echo(char **cmd, t_info *info)
{
	int		i;
	int		fl_n;

	i = 1;
	fl_n = 0;
	if (cmd[1] && (!ft_strcmp(cmd[1], "-n")))
	{
		fl_n = 1;
		i = 2;
	}
	while (cmd && cmd[i])
	{
		ft_putstr_fd(cmd[i], 1);
		if (cmd[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (fl_n == 0)
		ft_putstr_fd("\n", 1);
	info->exit_status = 0;
	return (0);
}
