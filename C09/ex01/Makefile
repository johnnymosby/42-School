NAME=libft.a
DIR=:./srcs/
SFILES=ft_putchar.c \
				ft_swap.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_strcmp.c
OFILES=$(SFILES:.c=.o)
SRCS= $(addprefix $(DIR), $(SRS_FILES))
OBS= $(addprefix $(DIR), $(OBS_FILES))
HEADER=-I includes/

all:
	cc -Wall -Wextra -Werror -c $(SRCS) $(HEADER)
	mv -t $(DIR) $(OFILES)
	ar rc $(NAME) $(OBS)
$(NAME): all
clean:
		rm -f $(OBS)
fclean: clean
		rm -f $(NAME)
re: fclean all

