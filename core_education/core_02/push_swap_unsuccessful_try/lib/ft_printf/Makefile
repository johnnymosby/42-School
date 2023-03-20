NAME=libftprintf.a
SFILES=*.c
OFILES=$(SFILES:.c=.o)

all:	$(NAME)

$(NAME):
		cc -Wall -Wextra -Werror -c $(SFILES) ft_printf.h
		ar rc $(NAME) $(OFILES)
clean:
		rm -f $(OFILES)
		rm -f ft_printf.h.gch
fclean: clean
		rm -f $(NAME)
re: fclean all
