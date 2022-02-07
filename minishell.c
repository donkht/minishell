#include "minishell.h" 

int	main(int argc, char **argv, char **envp)
{
	char *str;

	(void)argc;
	(void)argv;
	(void)envp;
	while(1)
	{
		str = readline("minishell>");
		printf("%s\n", str);
		free(str);
	}


	return (1);
}


