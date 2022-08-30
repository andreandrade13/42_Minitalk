FLAGS = -Wall -Werror -Wextra
CC = gcc

SERVER = server
CLIENT = client

PRINTF = ft_printf
FLAGS = -Wall -Werror -Wextra -I$(PRINTF)/header -L$(PRINTF) -lftprintf

all:
		@make -s -C $(PRINTF)
		@gcc $(FLAGS) server.c -o $(SERVER)
		@gcc $(FLAGS) client.c -o $(CLIENT)
		@echo "Initialized Successfully Server and Client!"

clean:
		@make clean -s -C $(PRINTF)

fclean: clean
		@make fclean -s -C $(PRINTF)
		@rm -f $(SERVER) $(CLIENT)
		@echo "Server and Client executables were disable. Please run Makefile again."

re: fclean all