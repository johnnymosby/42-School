NAME	=	fractol
SRC		=	*.c
OBJ		=	$(SFILES:.c=.o)
INC		=	inc/

all:	$(NAME)

$(NAME):
		cc -Wall -Wextra -Werror -c $(SFILES) ft_printf.h
		ar rc $(NAME) $(OFILES)
clean:
		rm -f $(OFILES)
fclean: clean
		rm -f $(NAME)
re: fclean all
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

.PHONY : all, clean, fclean, re