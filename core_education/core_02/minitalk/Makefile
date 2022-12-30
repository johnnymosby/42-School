NAME	=	

CLIENT	=	client

SERVER	=	server

LIBFT	=	./lib/libft/libft.a

SRC_DIR	=	./src/

INC		=	./inc

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all:		$(CLIENT) $(SERVER)

$(NAME):	all

$(CLIENT):	$(LIBFT)
			$(CC) $(CFLAGS) $(SRC_DIR)client.c -I$(INC) $(LIBFT) -o $(CLIENT)

$(SERVER):	$(LIBFT)
			$(CC) $(CFLAGS) $(SRC_DIR)server.c -I$(INC) $(LIBFT) -o $(SERVER)

$(LIBFT):
			make -C ./lib/libft/

clean:
			make clean -C ./lib/libft/

fclean:		clean
			rm -f $(CLIENT) $(SERVER)
			make fclean -C ./lib/libft/

bonus:		$(LIBFT)
			$(CC) $(CFLAGS) $(SRC_DIR)client_bonus.c -I$(INC) $(LIBFT) -o $(CLIENT)
			$(CC) $(CFLAGS) $(SRC_DIR)server_bonus.c -I$(INC) $(LIBFT) -o $(SERVER)

re:		fclean all

PHONY:		all, clean, fclean, re
