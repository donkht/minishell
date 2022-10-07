/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_for_minishell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:41:56 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 14:38:43 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	input Control-C it is exit with code 2 (130 = 128 + 2)
*	rl_on_new_line(); A message to the update procedures that we have moved
* 	to a new (empty) line, usually after the output of a new line.
*	rl_replace_line("", 0); - Replace the contents of rl_line_buffer with the text
*	rl_redisplay(); - Change what's displayed on the screen 
*	to reflect the current contents of rl_line_buffer.
*/

static void	signal_int_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	signal_cmd_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd("^C", 1);
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	signal_quit_cmd_handler(int signal)
{
	if (signal == SIGQUIT)
	{
		ft_putstr_fd("^\\Quit: 3\n", 2);
		rl_on_new_line();
	}
}

void	signals_for_minishell(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, signal_int_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	signals_for_child(void)
{
	signal(SIGINT, signal_cmd_handler);
	signal(SIGQUIT, signal_quit_cmd_handler);
}
