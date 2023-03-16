NAME	=	push_swap

LIBFT	=	./lib/libft/libft.a

PRINTF	=	./lib/ft_printf/libftprintf.a

SRC_DIR	=	./src/

INC		=	./inc

SRC		=	./src/main.c ./src/handle_error.c ./src/handle_input.c \
			./src/sort_with_bubble_sort.c ./src/initialise_array.c \
			./src/swap.c ./src/push.c ./src/shift_up.c ./src/shift_down.c \
			./src/create_stack.c

OBJ		=	$(SRC:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib/libft/
			make -C ./lib/ft_printf/
			$(CC) $(OBJ) $(OFLAGS) $(LIBFT) $(PRINTF) -o $(NAME)

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./inc

clean:
			rm -f $(OBJ)
			make clean -C ./lib/libft/
			make clean -C ./lib/ft_printf/

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./lib/libft/
			make fclean -C ./lib/ft_printf/

re:			fclean all

.PHONY:		all, clean, fclean, re