NAME	=	fractol

LIBFT	=	./lib/libft/libft.a

SRC_DIR	=	./src/

INC		=	./inc

SRC		=	./src/fractol.c

OBJ		=	$(SRC:.c=.o)

UNAME	=	$(shell uname -s)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

ifeq ($(UNAME), Darwin)
		MLX		=	./lib/mlx_osx
		OFLAGS	= 	$(CFLAGS) -L $(MLX) -l mlx -framework OpenGl -framework Appkit
endif

ifeq ($(UNAME), Linux)
		MLX		=	./lib/mlx_linux
		OFLAGS	= 	$(CFLAGS) -L $(MLX) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib/libft/
			make -C $(MLX)
			$(CC) $(OBJ) $(OFLAGS) $(LIBFT) -o $(NAME)

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./inc

clean:
			rm -f $(OBJ)
			make clean -C ./lib/libft/
			make clean -C $(MLX)

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./lib/libft/

re:			fclean all

.PHONY:		all, clean, fclean, re