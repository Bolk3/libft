NAME:=				libft.a
TEST_NAME:=			libft.test

CC:=					cc
CFLAGS:=				-Wall -Wextra -Werror -I ./include
LCRITERION:=			-lcriterion --coverage 

COMMA:=				,
WRAP_LDFLAGS=		$(addprefix -Wl$(COMMA)--wrap=, $(WRAP))

SRC_DIR:=			src
TEST_DIR:=			test
SRC_OBJS=			$(addprefix $(SRC_DIR)/, $(FILES:.c=.o))
TEST_OBJS=			$(addprefix $(TEST_DIR)/, $(FILES:.c=.o))

FILES:=				ft_isalpha.c	\
					ft_isdigit.c	\
					ft_isalnum.c	\
					ft_isascii.c	\
					ft_isprint.c	\
					ft_strlen.c		\
					ft_memset.c		\
					ft_bzero.c		\
					ft_memcpy.c		\
					ft_memmove.c	\
					ft_strlcpy.c	\
					ft_strlcat.c	\
					ft_toupper.c	\
					ft_tolower.c	\
					ft_strchr.c		\
					ft_strrchr.c	\
					ft_strncmp.c	\
					ft_memchr.c		\
					ft_memcmp.c		\
					ft_strnstr.c	\
					ft_atoi.c		\
					ft_strdup.c		\
					ft_calloc.c		\
					ft_substr.c		\
					ft_strjoin.c	\
					ft_strtrim.c	\
					ft_split.c		\
					ft_itoa.c		\
					ft_strmapi.c	\
					ft_striteri.c	\
					ft_putchar_fd.c	\
					ft_putstr_fd.c	\
					ft_putendl_fd.c	\
					ft_putnbr_fd.c	\
					ft_lstnew.c		\
					ft_lstadd_front.c	\
					ft_lstsize.c	\
					ft_lstlast.c	\
					ft_lstadd_back.c	\
					ft_lstdelone.c	\
					ft_lstclear.c	\
					ft_lstiter.c	\
					ft_lstmap.c

WRAP:=				malloc

all:				$(NAME)

$(NAME):			$(SRC_OBJS)
					ar rcs $(NAME) $(SRC_OBJS)

$(SRC_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/%.o:	$(TEST_DIR)/%.c
					$(CC) $(CFLAGS) -c $< -o $@

test:				$(SRC_OBJS) $(TEST_OBJS)
					$(CC) $(WRAP_LDFLAGS) $(SRC_OBJS) $(TEST_OBJS) test/wraps.c $(LCRITERION) -o $(TEST_NAME)

clean:
					rm -rf $(SRC_OBJS)
					rm -rf $(TEST_OBJS)

fclean:				clean
					rm -f $(NAME) $(TEST_NAME)
					rm -f *.gc*

re:					fclean all

.PHONY:				re test clean fclean all
