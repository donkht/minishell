/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:46:02 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 20:14:59 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == ' ' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	check_mini_args(int argc, char **argv)
{
	if (argc > 1 && argv != NULL)
	{
		ft_putstr_fd("Error: Please run the program without arguments\n", 1);
		return (0);
	}
	return (1);
}

char	*ft_readline(t_info *info)
{
	char	*line;

	line = NULL;
	line = readline("minishell->$ ");
	if (line && *line)
		add_history(line);
	else if (line && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}	
	else if (!line)
	{
		ft_putstr_fd("exit\n", 1);
		info->exit_flag = 1;
	}
	return (line);
}

int	check_exec(char *cmd_path)
{
	struct stat	buffer;

	if (stat(cmd_path, &buffer) != 0)
		return (0);
	if ((buffer.st_mode & S_IFMT) == S_IFDIR)
		return (0);
	if ((buffer.st_mode & S_IXUSR))
		return (1);
	return (0);
}
