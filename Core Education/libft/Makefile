NAME=libft.a
DIR=srcs/
SFILES=*.c
OFILES=$(SFILES:.c=.o)
SRCS= $(addprefix $(DIR), $(SFILES))
OBS= $(addprefix $(DIR), $(OFILES))
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
