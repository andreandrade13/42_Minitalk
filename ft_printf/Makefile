# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andchris <andchris1987@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 15:01:13 by andchris          #+#    #+#              #
#    Updated: 2022/08/29 23:14:29 by andchris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c printf_c.c printf_percent.c printf_di.c printf_hex.c printf_str.c printf_u.c printf_pointer.c ft_atoi.c ft_strlen.c
   

BONUS = 

OBJ = ${SRC:.c=.o}

# OBJBONUS = 

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJ}
		ar rcs ${NAME} ${OBJ}

# bonus: ${OBJ} ${OBJBONUS}
# 		ar rcs ${NAME} ${OBJ} ${OBJBONUS}

all: ${NAME}

clean:
		${RM} ${OBJ} #${OBJBONUS}

fclean: clean
			${RM} ${NAME}

re: fclean all
