/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:02:33 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 14:43:42 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_info *info)
{
	int		i;
	t_env	*tmp;

	tmp = NULL;
	tmp = info->envp_list;
	i = 0;
	while (tmp != NULL)
	{
		printf("%s", tmp->key);
		printf("%c", tmp->separator);
		printf("%s\n", tmp->val);
		tmp = tmp->next;
	}
}

void	print_tokens(t_info *info)
{
	int		i;
	t_token	*tmp;

	tmp = NULL;
	tmp = info->tokens;
	i = 0;
	while (tmp != NULL)
	{
		printf("Type: %i, ", tmp->type);
		printf("Val: %s, ", tmp->content);
		printf("Len: %lu \n", tmp->length);
		tmp = tmp->next;
	}
}

void	print_env_old(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
