/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:08:29 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/26 15:08:10 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tkn_lstnew(char *content, int type, size_t tkn_length)
{
	t_token	*lst;

	lst = (t_token *)malloc(sizeof(t_token));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->type = type;
	lst->length = tkn_length;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

void	tkn_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*tmp;

	if (lst && new)
	{
		if (*lst)
		{
			tmp = tkn_lstlast(*lst);
			tmp->next = new;
			new->prev = tmp;
		}
		else
			*lst = new;
	}
}

t_token	*tkn_lstlast(t_token *lst)
{
	t_token	*tmp;

	tmp = lst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}	
	return (tmp);
}

void	tkn_lstdelone(t_token *lst, void (*del)(void*))
{
	if (lst && del)
	{	
		del(lst->content);
		free(lst);
		lst = NULL;
	}
}

void	tkn_lstclear(t_token **lst, void (*del)(void*))
{
	t_token	*tmp;

	if (*lst && lst && del)
	{	
		while (*lst)
		{
			tmp = (*lst)->next;
			tkn_lstdelone(*lst, del);
			*lst = tmp;
		}
		lst = NULL;
	}
}
