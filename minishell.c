/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:34:11 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/13 15:41:28 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	pid_t	p;

	(void)argc;
	(void)argv;
	   // new line
	(void)envp;
	while (1)
	{
		str = readline("minishell> ");
		add_history(str);
		printf("MODIFICATION\n"); // new line
		p = fork();
		if (p == 0)
		{
			str = ft_strjoin("/bin/", str);
			execve(str, argv, envp);
		}
		wait(0);
		free(str);
	}
	return (1);
}
