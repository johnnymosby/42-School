NAME	=	push_swap

CHECKER =	checker

LIBFT	=	./lib/libft/libft.a

PRINTF	=	./lib/ft_printf/libftprintf.a

SRC_DIR	=	./src/

BNS_DIR	=	./bonus/

INC		=	./inc

MAIN	=	main.c
MAIN	:=	$(addprefix $(SRC_DIR)/,$(MAIN))
OMAIN	=	$(MAIN:.c=.o)

BMAIN	=	checker.c
BMAIN	:=	$(addprefix $(BNS_DIR)/,$(BMAIN))
OBMAIN	=	$(BMAIN:.c=.o)

SRC		=	initialise.c free.c exit.c parse_input.c \
			transform.c ft_atoi_improved.c sort_with_bubble_sort.c\
			create_stack.c swap.c push.c shift_up.c shift_down.c\
			commands.c move_and_save.c print_commands.c sort.c\
			sort_small_numbers.c move_fr_a_to_b.c move_fr_b_to_a.c\
			print.c
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

OBJ		=	$(SRC:.c=.o)

BNS_SRC	=	get_next_line.c get_next_line_utils.c
BNS_SRC	:=	$(addprefix $(BNS_DIR)/,$(BNS_SRC))
BNS_OBJ	=	$(BNS_SRC:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ) $(OMAIN) $(LIBFT) $(PRINTF)
			$(CC) $(OBJ) $(OMAIN) $(CFLAGS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
			make -C ./lib/libft/

$(PRINTF):
			make -C ./lib/ft_printf/

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./inc

clean:
			rm -f $(OBJ) $(OMAIN)
			rm -f $(BNS_OBJ) $(OBMAIN)
			make clean -C ./lib/libft/
			make clean -C ./lib/ft_printf/

fclean:		clean
			rm -f $(NAME)
			rm -f $(CHECKER)
			make fclean -C ./lib/libft/
			make fclean -C ./lib/ft_printf/

re:			fclean all

bonus:	$(OBJ) $(OBMAIN) $(BNS_OBJ) $(LIBFT) $(PRINTF)
		$(CC) $(OBJ) $(OBMAIN) $(BNS_OBJ) $(CFLAGS) $(LIBFT) $(PRINTF) -o $(CHECKER)

.PHONY:		all, clean, fclean, re
