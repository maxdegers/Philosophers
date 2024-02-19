# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 00:46:08 by mbrousse          #+#    #+#              #
#    Updated: 2024/02/19 00:50:07 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	philo.c

OBJ_D	= objs/

SRC_D	= src/

OBJECTS = ${SOURCES:%.c=${OBJ_D}%.o}

HEADER 	=	includes/philo.h

H_D 	= 	.

NAME			=	philo

CC 				=	cc

FLAGS 			=	-Wall -Wextra -Werror

all:
	@make --no-print-directory ${NAME}

${OBJ_D}:
	@mkdir -p ${OBJ_D}
	
${OBJECTS} : ${OBJ_D}%.o: ${SRC_D}%.c  ${HEADER} Makefile
	${CC} ${FLAGS} -I/usr/include -c $< -o $@

${NAME}: ${OBJ_D} ${OBJECTS} Makefile
	$(CC) $(OBJECTS) -o $(NAME)

clean:
	@rm -rf ${OBJ_D} 

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re