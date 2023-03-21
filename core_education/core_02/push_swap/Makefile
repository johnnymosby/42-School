NAME	=	push_swap

LIBFT	=	./lib/libft/libft.a

PRINTF	=	./lib/ft_printf/libftprintf.a

SRC_DIR	=	./src/

INC		=	./inc

SRC		=	main.c initialise.c free.c exit.c parse_input.c \
			transform.c ft_atoi_improved.c sort_with_bubble_sort.c\
			\
			print.c
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

OBJ		=	$(SRC:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(PRINTF)
			$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
			make -C ./lib/libft/

$(PRINTF):
			make -C ./lib/ft_printf/

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