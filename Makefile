SRC = main.c parsing/free.c parsing/tokenizer.c parsing/tokenizer_utils.c parsing/ast_parser.c parsing/parser_utils.c\
	parsing/expanding.c parsing/print_helper.c parsing/expanding_utils.c parsing/check_errors.c 

NAME = minishell
HEADER = includes/minishell.h
OBJ = ${SRC:.c=.o}

CC = cc 
CFLAGS = -Wall -Wextra -Werror -Iincludes

LIB_DIR = libft
LIB_FILE = libft.a
LIB = $(LIB_DIR)/$(LIB_FILE)

RM = rm -f

all: ${NAME}

${NAME}: ${OBJ} ${HEADER} ${LIB}
	${CC} $(CFLAGS) ${OBJ} ${LIB} -lreadline -o ${NAME}

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	${RM} ${OBJ}
	$(MAKE) clean -C $(LIB_DIR)
fclean:
	${RM} ${NAME} ${OBJ}
	$(MAKE) fclean -C $(LIB_DIR)
re: fclean all
