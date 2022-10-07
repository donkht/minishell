/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:40:37 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 15:08:40 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	red_inp(t_info *info, char *file, int oflag)
{
	int	fd_in_file;

	fd_in_file = open(file, oflag);
	if (fd_in_file < 0)
		error_out_status("Error: redirect", strerror(errno), 1, info);
	else
	{
		dup2(fd_in_file, STD_IN);
		close(fd_in_file);
	}
}

static void	red_out(t_info *info, char *file, int oflag)
{
	int	fd_file;

	fd_file = open(file, oflag, 0777);
	if (fd_file < 0)
		error_out_status("Error: redirect", strerror(errno), 1, info);
	else
	{
		dup2(fd_file, STD_OUT);
		close(fd_file);
	}
}

void	check_mk_re(t_token *cur_tkn, t_token *end, \
int *save_fd, t_info *info)
{
	while (cur_tkn != end)
	{
		if (!cur_tkn->next)
			break ;
		if (cur_tkn->type == TOKEN_REDIR && cur_tkn->next->type == TOKEN_FILE)
		{
			if (!ft_strcmp(cur_tkn->content, ">"))
				red_out(info, cur_tkn->next->content, \
				O_WRONLY | O_CREAT | O_TRUNC);
			else if (!ft_strcmp(cur_tkn->content, "<"))
				red_inp(info, cur_tkn->next->content, \
				O_RDONLY | O_CREAT);
			else if (!ft_strcmp(cur_tkn->content, ">>"))
				red_out(info, cur_tkn->next->content, \
				O_WRONLY | O_CREAT | O_APPEND);
			else if (!ft_strcmp(cur_tkn->content, "<<"))
				heredoc_inp(info, cur_tkn->next->content, save_fd);
			cur_tkn = cur_tkn->next;
		}
		cur_tkn = cur_tkn->next;
	}
}
