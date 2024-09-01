# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 09:17:32 by marvin            #+#    #+#              #
#    Updated: 2024/08/30 23:45:51 by ele-borg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables

SRC_FILES = push_swap.c \
			error_management.c \
			algorithm.c \
			instructions.c \
			lst_functions_parta.c \
			lst_functions_partb.c \
			utils_functions.c \
			small_arguments.c \
			five_arguments.c \
			sense_rotation.c \
			value_to_push.c \
			numbers_of_instructions.c \
			actions.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -I.

CC = cc

#rules

all: ${NAME} 

${NAME}: ${OBJ_FILES}
	${CC} ${FLAGS} ${OBJ_FILES} -o ${NAME}

${OBJ_FILES}: %.o: %.c
	${CC} -c ${FLAGS} $< -o $@

clean: 
	rm  -f ${OBJ_FILES}

fclean: clean
	rm -f ${NAME}

re: fclean all

reclean : all clean

.PHONY: all clean fclean re