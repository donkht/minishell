/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:39:50 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/26 23:09:43 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	errno returns - ENODEV (No such device), 
*	ENOMEM (not enough memory) or 
*	ERANGE (area error - Numerical result out of range).
*/

static void	pwd_error_exit(t_info *info, int error_nbr)
{
	if (info->envp_list != NULL)
		free_env(&info->envp_list);
	ft_putstr_fd("Error getcwd: ", 2);
	ft_putendl_fd(strerror(error_nbr), 2);
	exit(error_nbr);
}

int	built_in_pwd(t_info *info)
{
	char	*buffer;

	buffer = NULL;
	buffer = getcwd(NULL, 0);
	if (!buffer)
		pwd_error_exit(info, ERANGE);
	ft_putendl_fd(buffer, 1);
	free(buffer);
	info->exit_status = 0;
	return (0);
}
