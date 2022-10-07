/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:47:28 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/27 23:00:54 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_out_status(char *text_err, char *strer, int status, t_info *info)
{
	ft_putstr_fd("minishell: ", STD_ERR);
	ft_putstr_fd(text_err, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	ft_putendl_fd(strer, STD_ERR);
	info->exit_status = status;
}

void	sintax_error_out_status(char *text_error, int status, t_info *info)
{
	ft_putendl_fd(text_error, STD_ERR);
	info->exit_status = status;
}

void	sintax_error_output(char **line, char *text_error)
{
	ft_putendl_fd(text_error, STD_ERR);
	free(*line);
	*line = NULL;
}

void	malloc_error_exit(t_info *info)
{
	if (info->envp_list != NULL)
		free_env(&info->envp_list);
	ft_putstr_fd("Memory error: ", 2);
	ft_putendl_fd(strerror(12), 2);
	exit(12);
}
