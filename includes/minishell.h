/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:22:37 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 15:58:28 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

/* Linux Standard Streams */
enum	e_stdfd{
	STD_IN = 0,
	STD_OUT = 1,
	STD_ERR = 2
};

/* Errors texts */
# define T_UNEXP_SCOLON "minishell: syntax error near unexpected token `;'"
# define T_UNEXP_BSLASH "minishell: syntax error near unexpected token `\\'"
# define T_UNEXP_QUOTES "minishell: syntax error - open quotes"
# define T_UNEXP_BRACKETS "minishell: syntax error - brackets"
# define T_UNEXP_PIPES "minishell: syntax error near unexpected token `|'"
# define T_BAD_REDIR_UNCOR_FILE "minishell: syntax error uncorrect redirect"
# define ERR_REDIRECT "minishell: redirect"

/* TOKEN TYPES */
enum	e_ttype{
	TOKEN_WORD = 1,
	TOKEN_BLT_IN = 2,
	TOKEN_PIPE = 3,
	TOKEN_REDIR = 4,
	TOKEN_FILE = 5,
	TOKEN_HEREDOC = 6
};

/* list of linux environment variables */
typedef struct s_env
{
	char			*key;
	char			*val;
	int				separator;
	struct s_env	*next;
}		t_env;

/* token list */
typedef struct s_token
{
	int				type;
	char			*content;
	size_t			length;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_parts
{
	char	*before;
	char	*value;
	char	*after;
	char	*ptr;
}	t_parts;

/*  main structure */
typedef struct s_info
{
	t_env	*envp_list;
	char	**envp;
	char	*path;
	int		exit_flag;
	char	*line;
	t_token	*tokens;
	int		cmd_count;
	int		exit_status;
}	t_info;

int		mini_cycle(t_info *info);

/* environment management */
void	envp_to_list(t_info *info, char **envp);
char	*find_envair_value(t_info *info, char *key);
void	envp_add(t_info *info, char *key, char *val, int separator);
void	build_env_from_list(t_info *info, t_env *envp_list);
t_env	*env_list_search(t_info *info, char *key);
void	env_lst_delone(t_env *env, void (*del)(void*));
void	build_env_from_list(t_info *info, t_env *envp_list);
char	**build_env_for_export(t_info *info);
void	print_env_array(char **envp);
int		ft_count_envp(t_env *envp_list);
bool	find_env_key(t_info	*info, char *key);
void	replace_env_val(t_info	*info, char *key, char *new_val);

/* Initialization minisshell */
void	init_minishell_vars(t_info *info);
void	ctrl_controller(void);
void	signals_for_minishell(void);
void	signals_for_child(void);
void	here_doc_intsig(int signal);

/* minishell utils */
int		check_mini_args(int argc, char **argv);
char	*ft_readline(t_info *info);

/* SHLVL */
void	shlevel_increase(t_info	*info);

/* lexer */
int		lexer(t_info *info);
int		syntax_inp(char **line);
void	sintax_error_output(char **line, char *text_error);
int		check_open_quotes(char *str);
int		check_semicolon_bslash(char **line);
int		check_brackets(char *control_str);
int		check_uncorrect_pipes(char *control_str);
void	spaces_convert(char **line);
void	add_spaces_around_token(char **line);
int		check_spaces_near_oper(char *line, char *line_init);
char	*add_tknsep_spaces(char **line, char *op_beg, char *l_begin);
void	quotes_handler(char **content, t_info *info);
void	tilda_handler(char **content, t_info *info);

/* Parsing */
void	check_mk_re(t_token *current, t_token *end, int *save_fd, t_info *info);
void	check_pipe_rcrs(t_info *info, t_token *tokens_first, int *old_pipe_inp);
void	dollar_vars_uncover(char **value, t_info *info);
void	dollar_alone(char **content, t_info *info);
void	dollar_dubbles(char **content, t_info *info);
void	uncover_value(char **variable, t_info *info);
char	**create_commands(t_token *first, t_token *pipe);
void	pipe_new(t_token *pipe_tkn, int *old_pipe_in);
void	identi_first_q(char *first_quote, char *token);
void	remove_all_quotes(t_parts *parts, char	**token_arg, int *end_quote);
void	identi_last_q(char *token, bool has_variable,
			char first_quote, int *end_quote);

/* Execute cmds */
void	executor_select(t_info *info, char **cmd);
void	heredoc_inp(t_info *info, char *eof, int *save_fd);

/* Tokens List manage*/
t_token	*tkn_lstlast(t_token *lst);
void	tkn_lstadd_back(t_token **lst, t_token *new);
t_token	*tkn_lstnew(char *content, int type, size_t tkn_length);
void	tkn_lstclear(t_token **lst, void (*del)(void*));

/* built_in */
int		builtin_check(char *content);
void	run_built_ins(char **cmd, t_info *info);
int		built_in_echo(char **cmd, t_info *info);
int		built_in_pwd(t_info *info);
void	built_in_cd(char *dir, t_info *info);
void	built_in_exit(char **cmd, t_info *info);
void	built_in_env(t_info *info);
void	built_in_unset(char **cmd, t_info *info);
int		built_in_export(char **cmd, t_info *info);

bool	if_export_error(t_info *info, char *str);
void	export_error(t_info *info, char *var);

/* Utils */
int		ft_isspace(int c);
int		ft_strcmp(const char *s1, const char *s2);
int		check(char *line, int i, int *index, char c);
int		tkn_blt_in_check(char *content, size_t tkn_length);
void	error_out_status(char *text_err, char *strer, int status, t_info *info);
void	sintax_error_out_status(char *text_error, int status, t_info *info);
void	print_tokens(t_info *info);
void	print_env(t_info *info);
void	malloc_error_exit(t_info *info);
int		check_exec(char *cmd_path);
char	*find_exp_var(char *value, int *i);
int		size_of_var(char *parts, int *index);
int		only_dollar_in_wallet(char *value);
int		make_temp_file(t_info *info);
void	make_temp_file_inp(void);
void	clear_temp_file_inp(void);
void	act_variable_one_quote(t_parts *parts, char **value, int i);

/* Free Data*/
void	free_env(t_env **envp_list);
void	free_all_data(t_info *info);
void	xx_arr_clean(char **ptr);
void	free_element(void **ptr);
void	free_struct_t_parts(t_parts *parts);

#endif