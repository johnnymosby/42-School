NAME	=	fractol
SRC		=	*.c
OBJ		=	$(SRC:.c=.o)
INC		=	inc/

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
		rm -f $(OFILES)
fclean: clean
		rm -f $(NAME)
re: fclean all
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

.PHONY : all, clean, fclean, re