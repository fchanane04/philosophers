# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 15:18:26 by fchanane          #+#    #+#              #
#    Updated: 2022/10/26 23:11:47 by fchanane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS	= philosophers.h

NAME	=	philo

CC = gcc  

CFLAGS	=  -Wall -Wextra -Werror -pthread

RM		=	rm -f

SRC =	philosophers.c\
		libft.c\
		param_parser.c\
		param_init.c\
		simulator.c\
		supervisor.c\
		timer.c\
		printer.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

