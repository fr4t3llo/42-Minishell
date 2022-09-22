# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 15:37:33 by skasmi            #+#    #+#              #
#    Updated: 2022/09/22 16:41:04 by skasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=minishell
NAME2=minishell.h

SRCS=	minishell.c \
		libft/ft_lst_addback_env.c \
		libft/ft_lst_last_env.c \
		libft/ft_lstnew_env.c \
		libft/ft_split.c \
		libft/ft_strcpy.c \
		libft/ft_strlen.c \
		libft/ft_strcmp.c \
		libft/ft_atoi.c \
		bulletin/env.c \
		bulletin/export.c \
		bulletin/pwd.c \
		bulletin/cd.c \
		bulletin/exit.c \
		bulletin/final.c \
		src/syntax_error.c \
		src/expand.c \
	

BOBJCTS=$(BSRCS:%.c=%.o)

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS) $(NAME2)

		$(CC) $(CFLAGS) $(OBJCTS) -lreadline -o $(NAME) 
				
		@echo "\033[90m███╗░░░███╗██╗███╗░░██╗██╗░██████╗██╗░░██╗███████╗██╗░░░░░██╗░░░░░\033[0m" 
		@echo "\033[90m████╗░████║██║████╗░██║██║██╔════╝██║░░██║██╔════╝██║░░░░░██║░░░░░\033[0m"
		@echo "\033[91m██╔████╔██║██║██╔██╗██║██║╚█████╗░███████║█████╗░░██║░░░░░██║░░░░░\033[0m"
		@echo "\033[91m██║╚██╔╝██║██║██║╚████║██║░╚═══██╗██╔══██║██╔══╝░░██║░░░░░██║░░░░░ \033[0m"
		@echo "\033[93m██║░╚═╝░██║██║██║░╚███║██║██████╔╝██║░░██║███████╗███████╗███████╗ \033[0m"
		@echo "\033[93m╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝╚═════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝\033[0m"
			
all: $(NAME)
	
clean:
				rm -f $(OBJCTS) $(BOBJCTS)

fclean: clean
				rm -f $(NAME)

re: fclean all