NAME=				libft.a
TEST_NAME=			libft.test

CC=					cc
CFLAGS=				-Wall -Wextra -Werror
CCRITERION=			-lcriterion --coverage

SRC_DIR=			src
TEST_DIR=			test

SRC_OBJS=			$(addprefix $(SRC_DIR)/, $(FILES:.c=.o))
TEST_OBJS=			$(addprefix $(TEST_DIR)/, $(FILES:.c=.o))

FILES=				ft_isalpha.c	\
					ft_isdigit.c	\
					ft_isalnum.c	\
					ft_isascii.c	\
					ft_isprint.c	\
					ft_strlen.c		\


all:				$(NAME)

$(NAME):			$(SRC_OBJS)
					ar rcs $(NAME) $(SRC_OBJS)

$(SRC_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/%.o:	$(TEST_DIR)/%.c
					$(CC) $(CFLAGS) -c $< -o $@

test:				$(SRC_OBJS) $(TEST_OBJS)
					$(CC) $(SRC_OBJS) $(TEST_OBJS) $(CCRITERION) -o $(TEST_NAME)
					./$(TEST_NAME) --verbose

clean:
					rm -rf $(SRC_OBJS) $(TEST_OBJS)

fclean:				clean
					rm -f $(NAME) $(TEST_NAME)

re:					fclean all

.PHONY:				re test clean fclean all
