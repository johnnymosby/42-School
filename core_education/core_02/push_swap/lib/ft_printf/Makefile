NAME=libftprintf.a
SFILES=ft_printf.c    ft_printf_p.c  ft_printf_x.c    ft_putstr.c \
	ft_printf_s.c  ft_print_xbig.c  ft_strcreate.c \
	ft_printf_i.c  ft_printf_u.c  ft_putchar.c
OFILES=$(SFILES:.c=.o)
CFLAGS=-Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OFILES)
		cc $(CFLAGS) -c $(SFILES) ft_printf.h
		ar rc $(NAME) $(OFILES)

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o)
clean:
		rm -f $(OFILES)
		rm -f ft_printf.h.gch
fclean: clean
		rm -f $(NAME)
re: fclean all
