/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:05:23 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 15:21:34 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_error(t_info *info, char *var)
{
	info->exit_status = 1;
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(var, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

bool	if_export_error(t_info *info, char *str)
{
	if ((!ft_isalpha(str[0]) && str[0] != '_') \
	|| (str[0] == '_' && str[1] == '\0'))
	{
		export_error(info, str);
		return (true);
	}
	return (false);
}
