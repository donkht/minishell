/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 03:06:10 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 15:52:47 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_env **envp_list)
{
	t_env	*tmp;
	t_env	*curr;

	tmp = NULL;
	curr = NULL;
	if (*envp_list)
		curr = *envp_list;
	while (curr)
	{
		tmp = curr;
		if (tmp->key)
			free(tmp->key);
		if (tmp->val)
			free(tmp->val);
		curr = curr->next;
		free(tmp);
		tmp = NULL;
	}
	*envp_list = NULL;
}

void	free_all_data(t_info *info)
{
	if (info)
	{
		if (info->envp_list != NULL)
			free_env(&info->envp_list);
	}
	info = NULL;
}

void	free_element(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	free_struct_t_parts(t_parts *parts)
{
	free_element((void **)&parts->before);
	free_element((void **)&parts->value);
	free_element((void **)&parts->after);
}

void	xx_arr_clean(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		free(str[i - 1]);
		i--;
	}
	free(str);
}
