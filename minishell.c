#include "minishell.h" 

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	pid_t	p;
	(void)argc;
	(void)argv;
	(void)envp;
	while(1)
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


