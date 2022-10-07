/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:20:25 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 15:05:00 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (!check_mini_args(argc, argv))
		return (1);
	init_minishell_vars(&info);
	envp_to_list(&info, envp);
	shlevel_increase(&info);
	ctrl_controller();
	if (mini_cycle(&info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
