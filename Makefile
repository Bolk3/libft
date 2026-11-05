NAME=			libft.a
TEST=			libft.test

CXX=			g++
CXXFLAGS=		-std=c++17 -Wall -Wextra -Werror -I ./include/
CC=				cc
CFLAGS=			-Wall -Wextra -Werror -I ./include/

GTEST_LIBS=		-lgtest -lgtest_main -lpthread

WRAPS=			-Wl,--wrap=malloc -Wl,--wrap=free

SRC=			./src/ft_lstnew.c
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
