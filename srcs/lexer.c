/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:05:20 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 14:26:08 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	type_token(t_token *tkn_last, char *content, int *type, size_t tkn_len)
{
	int	prev_token;

	prev_token = 0;
	if (tkn_last != NULL)
		prev_token = tkn_last->type;
	if ((prev_token != TOKEN_REDIR) && (!(ft_strncmp(content, "echo", tkn_len)) \
	|| !(ft_strncmp(content, "cd", tkn_len)) \
	|| !(ft_strncmp(content, "pwd", tkn_len)) \
	|| !(ft_strncmp(content, "export", tkn_len)) \
	|| !(ft_strncmp(content, "unset", tkn_len)) \
	|| !(ft_strncmp(content, "env", tkn_len)) \
	|| !(ft_strncmp(content, "exit", tkn_len))))
		*type = TOKEN_BLT_IN;
	else if (!ft_strncmp(content, ">", tkn_len) || \
	!ft_strncmp(content, "<", tkn_len) || \
	!ft_strncmp(content, ">>", tkn_len) || !ft_strncmp(content, "<<", tkn_len))
		*type = TOKEN_REDIR;
	else if (!(ft_strncmp(content, "|", tkn_len)))
		*type = TOKEN_PIPE;
	else if (prev_token == TOKEN_REDIR)
		*type = TOKEN_FILE;
	else
		*type = TOKEN_WORD;
}

int	go_to_end(char *line, int beg_tk, int *end_tk)
{
	while (line[beg_tk] != ' ' && line[beg_tk])
	{
		if ((line[beg_tk] == '\'' || line[beg_tk] == '\"') \
		&& check(line, beg_tk, &beg_tk, line[beg_tk]))
			;
		beg_tk++;
	}
	*end_tk = beg_tk;
	return (beg_tk);
}

void	add_tkn_back(t_info *info, char *line, int beg_tk, int end)
{
	char	*content;
	int		type;
	size_t	tkn_len;
	t_token	**token_lst;

	token_lst = &info->tokens;
	content = ft_substr(line, beg_tk, (end - beg_tk));
	if (!content)
		return ;
	if (ft_strncmp(content, "~", 2) == 0)
		tilda_handler(&content, info);
	else if (!ft_strncmp(content, "$", 2))
		dollar_alone(&content, info);
	else if (!ft_strncmp(content, "$$", 3))
		dollar_dubbles(&content, info);
	else if (only_dollar_in_wallet(content))
		dollar_alone(&content, info);
	else if (ft_strchr(content, '\'') || ft_strchr(content, '\"'))
		quotes_handler(&content, info);
	else if (ft_strchr(content, '$'))
		dollar_vars_uncover(&content, info);
	tkn_len = ft_strlen(content);
	type_token(tkn_lstlast(*token_lst), content, &type, tkn_len);
	tkn_lstadd_back(token_lst, tkn_lstnew(content, type, tkn_len));
}

int	get_tokens(t_info *info, char *line, int *beg_tk, int *end_tk)
{
	int	end;

	while (line[*beg_tk] == ' ')
		*beg_tk = *beg_tk + 1;
	if (!line[*beg_tk])
		return (0);
	end = go_to_end(line, *beg_tk, end_tk);
	add_tkn_back(info, line, *beg_tk, end);
	*beg_tk = *end_tk;
	if (line[*beg_tk])
		*beg_tk = *beg_tk + 1;
	return (1);
}

int	lexer(t_info *info)
{
	int	beg_tk;
	int	end_tk;

	if (syntax_inp(&info->line))
		return (0);
	spaces_convert(&info->line);
	add_spaces_around_token(&info->line);
	beg_tk = 0;
	end_tk = beg_tk;
	while ((info->line)[beg_tk])
		if (get_tokens(info, info->line, &beg_tk, &end_tk) == 0)
			break ;
	return (1);
}
