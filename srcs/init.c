/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:01:29 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 22:18:34 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 	
*	void	ctrl_controller(void)
*	Get the current configuration of the serial interface
* 	https://en.wikibooks.org/wiki/Serial_Programming/termios
*	Input flags - Turn off input processing
*	TCSANOW - the configuration is changed immediately.
*	tcgetattr - successful completion, 0 Otherwise, -1 or errno
*	tcsetattr - function shall set the parameters associated with the terminal			
*/

void	ctrl_controller(void)
{
	struct termios	config;

	if (tcgetattr(0, &config) < 0)
		return ;
	config.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, TCSANOW, &config) < 0)
		return ;
}

void	init_minishell_vars(t_info *info)
{
	info->exit_flag = 0;
	info->line = NULL;
	info->envp_list = NULL;
	info->tokens = NULL;
	info->envp = NULL;
	info->path = NULL;
}
