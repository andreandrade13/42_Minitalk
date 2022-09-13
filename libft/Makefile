# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andchris <andchris1987@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 15:01:13 by andchris          #+#    #+#              #
#    Updated: 2022/09/13 21:50:25 by andchris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c printf_c.c printf_percent.c printf_di.c printf_hex.c printf_str.c printf_u.c printf_pointer.c ft_atoi.c ft_strlen.c

OBJ = ${SRC:.c=.o}

# OBJBONUS = 

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJ}
		@ar rcs ${NAME} ${OBJ}

all: ${NAME}

clean:
		@rm -f ${OBJ} #${OBJBONUS}

fclean: clean
			@rm -f ${NAME}

re: fclean all
