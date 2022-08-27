# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 15:37:33 by skasmi            #+#    #+#              #
#    Updated: 2022/08/27 20:34:34 by skasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=minishell
NAME2=minishell.h

SRCS=minishell.c \
	

BOBJCTS=$(BSRCS:%.c=%.o)

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS) $(NAME2)
		$(CC) $(CFLAGS)  $(OBJCTS) -lreadline -o $(NAME) 
			
all: $(NAME)
	
clean:	
				rm -f $(OBJCTS) $(BOBJCTS)

fclean: clean
				rm -f $(NAME)

re: fclean all  