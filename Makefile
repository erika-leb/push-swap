# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 09:17:32 by marvin            #+#    #+#              #
#    Updated: 2024/07/24 09:17:32 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables

SRC_FILES = push_swap.c \
OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -I.

CC = cc

#rules

all: ${SUBDIR}_all ${NAME} 

${SUBDIR}_all:
	make -C ${SUBDIR}

${NAME}: ${OBJ_FILES}
	${CC} ${FLAGS} ${OBJ_FILES} -lft

${OBJ_FILES}: %.o: %.c
	${CC} -c ${FLAGS} $< -o $@

clean: 
	rm  -f ${OBJ_FILES}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re