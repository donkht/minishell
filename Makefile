NAME	= 	minishell

SRC_FOLDER = ./
HEADER_FOLDER = ./
LIBFT_FOLDER = ./libft/
#READLINE_FOLDER = $(shell brew --prefix readline)/lib/
HEADER_READLINE_FOLDER = $(shell brew --prefix readline)

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