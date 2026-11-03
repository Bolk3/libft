# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: resonnet <resonnet@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/02 11:14:49 by resonnet          #+#    #+#              #
#    Updated: 2026/11/03 14:48:03 by resonnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

OBJET		= $(FILES:.c=.o)

FILES		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
			  ft_strlcpy.c ft_strlcat.c	ft_toupper.c ft_tolower.c ft_strchr.c\
			  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c	ft_strnstr.c\
			  ft_atoi.c	ft_strdup.c ft_calloc.c	ft_substr.c	ft_strjoin.c\
			  ft_strtrim.c ft_split.c ft_itoa.c	ft_strmapi.c ft_striteri.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c	\
			  ft_lstnew.c ft_lstadd_front.c	ft_lstsize.c ft_lstlast.c\
			  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c	ft_lstiter.c ft_lstmap.c

%.o:		%.c
			$(CC) $(CFLAGS) -c $^ -o $@

$(NAME):	$(OBJET)
			ar rs $@ $^

all:		$(NAME)

clean:
			rm -rf $(OBJET)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		re all clean fclean
