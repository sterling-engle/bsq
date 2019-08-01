# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 22:36:17 by sengle            #+#    #+#              #
#    Updated: 2019/07/31 22:56:18 by sengle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bsq

SRCS	=	./src/main.c \
			./src/algo_bsq.c \
			./src/display.c \
			./src/grid.c \
			./src/struct_gestion.c \
			./src/bsq.c \
			./src/input.c \
			./src/read.c

OBJS	=	./main.o \
			./algo_bsq.o \
			./display.o \
			./grid.o \
			./struct_gestion.o \
			./bsq.o \
			./input.o \
			./read.o

FLAGS	=	-g -Werror -Wall -Wextra

INCS	=	./include

$(NAME):	all

all:
			gcc -c $(FLAGS) $(SRCS) -I $(INCS) 
			gcc -o $(NAME) $(FLAGS) $(OBJS)

clean: 
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
