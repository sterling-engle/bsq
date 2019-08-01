# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 22:36:17 by sengle            #+#    #+#              #
#    Updated: 2019/08/01 10:14:11 by sengle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	=	bsq

SRCS	=	src/main.c src/bsq_algo.c src/display.c src/grid.c \
			src/new_square.c src/input.c src/read_map.c

OBJS	=	main.o bsq_algo.o display.o grid.o new_square.o input.o read_map.o

FLAGS	=	-g -Werror -Wall -Wextra

INCS	=	./include

$(PROG):	all

all:		$(SRCS)
			gcc -c $(FLAGS) $(SRCS) -I $(INCS) 
			gcc -o $(NAME) $(FLAGS) $(OBJS)

clean: 
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
