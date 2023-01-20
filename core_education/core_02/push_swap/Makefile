NAME	=	push_swap

LIBFT	=	./lib/libft/libft.a

SRC_DIR	=	./src/

INC		=	./inc

SRC		=	./src/push_swap.c

OBJ		=	$(SRC:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib/libft/
			$(CC) $(OBJ) $(OFLAGS) $(LIBFT) -o $(NAME)

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./inc

clean:
			rm -f $(OBJ)
			make clean -C ./lib/libft/

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./lib/libft/

re:			fclean all

.PHONY:		all, clean, fclean, re