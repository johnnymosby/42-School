NAME=libftprintf.a
SFILES=*.c
OFILES=$(SFILES:.c=.o)

all:	$(NAME)

$(NAME):
		cc -Wall -Wextra -Werror -c $(SFILES) libftprintf.h
		ar rc $(NAME) $(OFILES)
clean:
		rm -f $(OFILES)
fclean: clean
		rm -f $(NAME)
re: fclean all
