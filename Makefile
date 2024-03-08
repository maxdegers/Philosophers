# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 00:46:08 by mbrousse          #+#    #+#              #
#    Updated: 2024/03/08 16:34:05 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	philo.c\
			checker.c\
			error.c\
			initialization.c\
			philo_utils.c\
			atoi.c\
			time.c\
			routine.c\
			forks.c

OBJ_D	= .objs/

SRC_D	= src/

OBJECTS = ${SOURCES:%.c=${OBJ_D}%.o}

HEADER_DIR      =       ./includes

HEADER  =       $(HEADER_DIR)/philo.h

NAME			=	philo

CC 				=	cc

FLAGS 			=	-Wall -Wextra -Werror

GREEN	  		=	 \033[1;32m
BLUE			=	 \033[1;34m
RED				=	 \033[1;31m
YELLOW	 		=	 \033[1;33m
DEFAULT			=	 \033[0m
UP	  			=	 "\033[A"
CUT				=	 "\033[K"

CHANGED    =    0

all:${NAME}

${OBJ_D}:
	@mkdir -p ${OBJ_D}
	
${OBJECTS} : ${OBJ_D}%.o: ${SRC_D}%.c  ${HEADER} Makefile
	@echo "$(YELLOW)Compiling [$<]$(DEFAULT)"
	@${CC} ${FLAGS} -I $(HEADER_DIR) -c $< -o $@
	@printf ${UP}${CUT}

${NAME}: ${OBJ_D} ${OBJECTS} Makefile
	@$(CC) $(OBJECTS) -lpthread -o $(NAME)
	@$(eval CHANGED=1)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

clean:
	@rm -rf ${OBJ_D} 

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL all:
	@if [ $(CHANGED) -eq 0 ]; then \
		echo "$(YELLOW)Nothing to do for all.$(DEFAULT)"; \
	fi