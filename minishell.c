/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:34:11 by gjacqual          #+#    #+#             */
/*   Updated: 2022/02/09 20:34:43 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	pid_t	p;

	(void)argc;
	(void)argv;
	(void)envp;
	while (1)
	{
		str = readline("minishell> ");
		add_history(str);
		// printf("\n");
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
