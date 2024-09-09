# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 09:17:32 by marvin            #+#    #+#              #
#    Updated: 2024/09/02 23:31:22 by ele-borg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables

# Fichiers sources communs
COMMON_FILES = instructions.c \
               lst_functions_parta.c \
               lst_functions_partb.c \
			   error_management.c \
			   utils_functions.c \

# Fichiers spécifiques pour le programme principal
SRC_FILES = push_swap.c \
			algorithm.c \
			small_arguments.c \
			five_arguments.c \
			sense_rotation.c \
			value_to_push.c \
			numbers_of_instructions.c \
			actions.c \
			$(COMMON_FILES)

# Fichiers spécifiques pour le bonus
SRC_BONUS_FILES = checker_bonus.c \
                  check_instruction_bonus.c \
                  get_next_line.c \
                  get_next_line_utils.c \
				  error_bonus.c \
                  $(COMMON_FILES)

OBJ_FILES = $(SRC_FILES:.c=.o)

OBJ_BONUS_FILES = $(SRC_BONUS_FILES:.c=.o)

NAME = push_swap

NAME_BONUS = checker

FLAGS = -Wall -Wextra -Werror -g3 -I.

CC = cc

#rules

all: ${NAME} 

${NAME}: ${OBJ_FILES}
	${CC} ${FLAGS} ${OBJ_FILES} -o ${NAME}

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS_FILES)
	$(CC) $(FLAGS) $(OBJ_BONUS_FILES) -o $(NAME_BONUS)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

clean: 
	rm  -f ${OBJ_FILES} ${OBJ_BONUS_FILES} 

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}

re: fclean all

reclean : all clean

.PHONY: all clean fclean re bonus