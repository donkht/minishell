# Program name
NAME	:=	minishell

# Compilation Parameters
CC	:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -g
RM	=	rm -f

# Libraries
LIBFT_DIR		:=	libft
LIBFT_LIB		:=	${LIBFT_DIR}/libft.a

#Readline
READLINE_DIR	:=	~/.brew/opt/readline
READLINE_LIB	:=	${READLINE_DIR}/lib
READLINE_INC	:=	${READLINE_DIR}/include	

# Includes
INC_DIR		:= includes
INC			:= includes/minishell.h

# Sources
SRCS_DIRS	=	./srcs/

# Search for src in catalogs
vpath %.c ${SRCS_DIRS}


SRCS	=	./srcs/minishell.c\
			./srcs/mini_cycle.c\
			./srcs/init.c\
			./srcs/mini_utils.c\
			./srcs/envp.c\
			./srcs/lexer.c\
			./srcs/lexer_add_spaces_around_token.c\
			./srcs/lexer_add_spaces_utils.c\
			./srcs/lexer_add_tknsep_spaces.c\
			./srcs/tests_code.c\
			./srcs/parser.c\
			./srcs/signals_for_minishell.c\
			./srcs/lexer_sintax.c\
			./srcs/lexer_sintax_input.c\
			./srcs/lexer_utils.c\
			./srcs/list_tokens.c\
			./srcs/shell_level_control.c\
			./srcs/errors.c\
			./srcs/redirects_handler.c\
			./srcs/here_doc.c\
			./srcs/heredoc_utils.c\
			./srcs/libft_candidates.c\
			./srcs/free_alloc_data.c\
			./srcs/built_in.c\
			./srcs/built_in_echo.c\
			./srcs/build_in_pwd.c\
			./srcs/built_in_cd.c\
			./srcs/built_in_exit.c\
			./srcs/built_in_env.c\
			./srcs/built_in_unset.c\
			./srcs/built_in_export.c\
			./srcs/list_env_manage.c\
			./srcs/cmd_manage.c\
			./srcs/env_build_from_lst.c\
			./srcs/env_build_for_export.c\
			./srcs/mini_executor.c\
			./srcs/quotes_handler.c\
			./srcs/quotes_handler_utils.c\
			./srcs/dollar_vars_uncover.c\
			./srcs/dollar_uncover_value.c\
			./srcs/dollar_checks.c\
			./srcs/exp_var_helpers.c\
			./srcs/tilda_handler.c\
			./srcs/export_utils.c
			

# Object files
OBJS_DIR 	:=	./objs

OBJS		:=  ${addprefix ${OBJS_DIR}/, ${notdir ${SRCS:.c=.o}}}

# Dependencies
DEP			=  ${OBJ:%.o=%.d}

# Targets
all 	:	 
				${MAKE} ${NAME}


${LIBFT_LIB}: FORCE
			@make -C ./${LIBFT_DIR}

FORCE:;

${NAME}	:	${OBJS} ${LIBFT_LIB}
			${CC} -L $(READLINE_LIB) -I ${READLINE_INC} ${CFLAGS} ${OBJS} -L ${LIBFT_DIR} -lft -lreadline -o ${NAME}
			@echo "\033[1;32mMinishell is ready\033[0m"	

${OBJS_DIR}: 
			@mkdir -p ${OBJS_DIR}

# Include all .d files
-include ${DEP}

${OBJS_DIR}/%.o : %.c ${INC} Makefile | ${OBJS_DIR}  
			${CC} -I ${READLINE_INC} ${CFLAGS} $(INC_DIR:%=-I %) ${LIBFT_DIR:%=-I %} -c $< -o $@

#Utils
clean:
			${MAKE} -C ${LIBFT_DIR} clean
			@rm -rf ${OBJS_DIR}
			@echo "\033[1;96mMinishell is Cleaned\033[0m"	

fclean: clean
			@${RM} ${NAME} ${LIBFT_LIB}
			@echo "\033[1;96mMinishell and Libft are Full Cleaned\033[0m"	

re			:	fclean all

# Leak Search
seleak	:
			@valgrind --leak-check=full --track-origins=yes ./minishell

seleakfull	:
			@valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=med --track-origins=yes ./minishell

norma	:
			norminette ./libft ./srcs ./includes ./srcs_bonus ./includes_bonus

.PHONY	: 	all libft clean fclean re norma seleak bonus
