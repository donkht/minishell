# Program name
NAME	:=	minishell

# Compilation Parameters
CC	:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
RM	=	rm -f

# Libraries
LIBFT_DIR	:=	libft
LIBFT_LIB	:=	${LIBFT_DIR}/libft.a

# Includes
INC_DIR		:= includes
INC			:= includes/minishell.h
# INC_B_DIR 	:= includes_bonus
# INC_B		:= includes_bonus/so_long_bonus.h

# Sources
SRCS_DIRS	=	./srcs/

# SRCS_B_DIRS	=	./srcs_bonus/

# Search for src in catalogs
vpath %.c ${if ${BONUS_MODE}, ${SRCS_B_DIRS}, ${SRCS_DIRS}}


SRCS	=	./srcs/minishell.c\

SRCS_B	=	./srcs_bonus/minishell.c\

# Object files
OBJS_DIR 	:=	./objs
OBJS_B_DIR 	:=	./objs_bonus

OBJS		:=  ${addprefix ${OBJS_DIR}/, ${notdir ${SRCS:.c=.o}}}
OBJS_B 		:=  ${addprefix ${OBJS_B_DIR}/, ${notdir ${SRCS_B:.c=.o}}}

# Dependencies
DEP			=  ${OBJ:%.o=%.d}
DEP_B		=  ${OBJ_B:%.o=%.d}

# Targets
all bonus	:	 
				${MAKE} ${NAME}

bonus		: export BONUS_MODE := 1

${LIBFT_LIB}: FORCE
			@make -C ./${LIBFT_DIR}
${MLX_LIB}	:
			@make -C ./${MLX_DIR}

FORCE:;

${NAME}	:	${if ${BONUS_MODE}, ${OBJS_B}, ${OBJS}} ${LIBFT_LIB}
			${CC} ${CFLAGS} ${if ${BONUS_MODE}, ${OBJS_B}, ${OBJS}} ${LIBFT_LIB} -o ${NAME}
			@echo "\033[1;32mMinishell is ready\033[0m"	

${OBJS_DIR}: 
			@mkdir -p ${OBJS_DIR}
${OBJS_B_DIR}:
			@mkdir -p ${OBJS_B_DIR}

# Include all .d files
-include ${DEP}
${OBJS_DIR}/%.o : %.c ${INC} Makefile | ${OBJS_DIR}  
			${CC} ${CFLAGS} $(INC_DIR:%=-I %) -c $< -o $@
			@echo "The object file is ready in OBJS_DIR"

${OBJS_B_DIR}/%.o : %.c ${INC_B} Makefile | ${OBJS_B_DIR} 
			${CC} ${CFLAGS} $(INC_B_DIR:%=-I %) -c $< -o $@
			@echo "The object BONUS file is ready in OBJS_B_DIR"

#Utils
clean:
			${MAKE} -C ${LIBFT_DIR} clean
			@rm -rf ${OBJS_DIR} ${OBJS_B_DIR}
			@echo "Minishell is Cleaned"	

fclean: clean
			@${RM} ${NAME} ${LIBFT_LIB}
			@echo "Minishell is Full Cleaned"	

re			:	fclean all

re_bonus	:	fclean bonus

# Leak Search
seleak	:
			@valgrind --leak-check=full --track-origins=yes ./minishell

seleakfull	:
			@valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=med --track-origins=yes ./minishell

norma	:
			norminette ./libft ./srcs ./includes ./srcs_bonus ./includes_bonus

.PHONY	: 	all libft clean fclean re norma seleak bonus
