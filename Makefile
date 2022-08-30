FLAGS = -Wall -Werror -Wextra
CC = gcc

SERVER = server
CLIENT = client

LIBFT = libft
FLAGS = -Wall -Werror -Wextra -I$(LIBFT)/header -L$(LIBFT) -lftprintf

all:
		@make -s -C $(LIBFT)
		@gcc $(FLAGS) server.c -o $(SERVER)
		@gcc $(FLAGS) client.c -o $(CLIENT)
		@echo "Initialized Successfully Server and Client!"

clean:
		@make clean -s -C $(LIBFT)

fclean: clean
		@make fclean -s -C $(LIBFT)
		@rm -f $(SERVER) $(CLIENT)
		@echo "Server and Client executables were disable. Please run Makefile again."

re: fclean all