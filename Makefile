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
INC_DIR 	:= includes
INC			:= includes/so_long.h
INC_B_DIR 	:= includes_bonus
INC_B		:= includes_bonus/so_long_bonus.h

# Sources
SRCS_DIRS	=	./srcs/

SRCS_B_DIRS	=	./srcs_bonus/

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
			${CC} ${CFLAGS} ${MLXFLAGS} ${if ${BONUS_MODE}, ${OBJS_B}, ${OBJS}} ${LIBFT_LIB} -o ${NAME}
			@echo "\033[1;32mSo_Long App is ready\033[0m"	

${OBJS_DIR}: 
			@mkdir -p ${OBJS_DIR}
${OBJS_B_DIR}:
			@mkdir -p ${OBJS_B_DIR}

# Include all .d files
-include ${DEP}
${OBJS_DIR}/%.o : %.c ${INC} ${GNL_INC} Makefile | ${OBJS_DIR}  
			${CC} ${CFLAGS} -Imlx $(INC_DIR:%=-I %) -c $< -o $@
			@echo "The object BONUS file is ready in OBJS_DIR"

${OBJS_B_DIR}/%.o : %.c ${INC_B} ${GNL_B_INC} Makefile | ${OBJS_B_DIR} 
			${CC} ${CFLAGS} -Imlx $(INC_B_DIR:%=-I %) -c $< -o $@
			@echo "The object BONUS file is ready in OBJS_B_DIR"

 
 
#Utils
clean:
			${MAKE} -C ${LIBFT_DIR} clean
			@rm -rf ${OBJS_DIR} ${OBJS_B_DIR}
			@echo "So_Long is Cleaned"	

fclean: clean
			@${RM} ${NAME} ${LIBFT_LIB}
			@echo "So_Long is Full Cleaned"	

re			:	fclean all

re_bonus	:	fclean bonus

norma	:
			norminette ./libft ./srcs ./includes ./srcs_bonus ./includes_bonus

.PHONY	: 	all libft clean fclean re norma seleak bonus





































##############
SRC_LIST = minishell.c

HEADER_LIST = minishell.h

SRCS = $(addprefix $(SRC_FOLDER), $(SRC_LIST))
HEADERS = $(addprefix $(HEADER_FOLDER), $(HEADER_LIST))

LIBFT= $(LIBFT_FOLDER)libft.a

OTHER_DEPEND = Makefile

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror 
RM		=	rm -f 

ALL_LIBS	= \
-lreadline \
-L $(LIBFT_FOLDER) -lft
ALL_HEADERS = \
-I $(HEADER_READLINE_FOLDER) \
-I $(LIBFT_FOLDER) \
-I $(HEADER_FOLDER)
# -L $(READLINE_FOLDER)

all:	$(NAME)

$(LIBFT): libft ;

%.o:	%.c
	$(CC) -c $(CFLAGS) $(ALL_HEADERS) $< -o $@

$(NAME):	$(LIBFT) $(OTHER_DEPEND) $(OBJS) $(HEADERS) 
	$(CC) $(CFLAGS) $(OBJS) $(ALL_LIBS) $(ALL_HEADERS) -o $(NAME)

libft:
	@make -C $(LIBFT_FOLDER)

clean:
	@$(RM) $(OBJS)
	@make -C libft clean

fclean:	clean
	@$(RM) $(NAME)
	@make -C libft fclean

re:	fclean $(NAME)

.PHONY:	all libft clean fclean re