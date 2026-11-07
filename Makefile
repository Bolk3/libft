NAME=			libft.a
TEST=			libft.test

CXX=			g++
CXXFLAGS=		-std=c++17 -Wall -Wextra -Werror -I ./include/
CC=				cc
CFLAGS=			-Wall -Wextra -Werror -I ./include/

ifneq ($(wildcard $(HOME)/googletest),)
	GTEST_DIR=		$(HOME)/googletest/googletest
	CXXFLAGS+=		-isystem $(GTEST_DIR)/include
	GTEST_LIBS=		$(GTEST_DIR)/libgtest.a $(GTEST_DIR)/libgtest_main.a -lpthread
else
	GTEST_LIBS=		-lgtest -lgtest_main -lpthread
endif

WRAPS=			-Wl,--wrap=malloc -Wl,--wrap=free

SRC=			./src/ft_lstnew.c\
				./src/ft_isalpha.c\
				./src/ft_isdigit.c\
				./src/ft_putchar_fd.c\
				./src/ft_putstr_fd.c\
				./src/ft_putendl_fd.c\
				./src/ft_putnbr_fd.c\
				./src/ft_strdup.c

TSRC=			$(SRC:./src/%.c=./test/%.cpp)

OBJS=			$(SRC:.c=.o)
TOBJS=			$(TSRC:.cpp=.o)

CHECKS=			./test/checks/checks.cpp\
				./test/checks/wraps.cpp

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

%.o:			%.cpp
				$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				ar rcs $@ $^

$(TEST):		$(OBJS) $(TOBJS)
				$(CXX) $(CXXFLAGS) $(CHECKS) $^ -o $(TEST) $(GTEST_LIBS) $(WRAPS)

all:			$(NAME)

clean:
				rm -rf $(OBJS)
				rm -rf $(TOBJS)

fclean:			clean
				rm -rf $(NAME)
				rm -rf $(TEST)

re:				fclean all

test:			$(TEST)

.PHONY:			re all test fclean clean
