# FLAGS = -Wall -Werror -Wextra -fsanitize=address
# CC = gcc

# SERVER = server
# CLIENT = client

# LIBFT = libft
# FLAGS = -Wall -Werror -Wextra -I$(LIBFT)/header -L$(LIBFT) -lftprintf

# all:
# 		@make -s -C $(LIBFT)
# 		@gcc $(FLAGS) server.c -o $(SERVER)
# 		@gcc $(FLAGS) client.c -o $(CLIENT)
# 		@echo "Initialized Successfully Server and Client!"

# clean:
# 		@make clean -s -C $(LIBFT)

# fclean: clean
# 		@make fclean -s -C $(LIBFT)
# 		@rm -f $(SERVER) $(CLIENT)
# 		@echo "Server and Client executables were disable. Please run Makefile again."

# re: fclean all

CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC_SERVER = server.c
OBJ_SERVER = ${SRC_SERVER:.c=.o}
SRC_CLIENT = client.c
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

SERVER = server
CLIENT = client

NAME = server client

all: ${SERVER} ${CLIENT}

${SERVER}: ${OBJ_SERVER}
			@make --silent -C ./libft
			@gcc ${FLAGS} ${OBJ_SERVER} -I ./libft -L ./libft -lftprintf -o ${SERVER}

${CLIENT}: ${OBJ_CLIENT}
			@make --silent -C ./libft
			@gcc ${FLAGS} ${OBJ_CLIENT} -I ./libft -L ./libft -lftprintf -o ${CLIENT}
			@echo "Initialized Successfully Server and Client!"

clean:
		@make clean -C ./libft
		@rm -f ${OBJS}

fclean: clean
		@make fclean -C ./libft
		@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
