CC=gcc
CFLAGS= -Wall -Wextra -Werror -c
NAME=libft.a
SRS_DIR=:./srcs/
SRS_FILES=ft_putchar.c \
				ft_swap.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_strcmp.c
OBS_FILES=$(SRS_FILES:.c=.o)
SRCS= $(addprefix $(SRS_DIR), $(SRS_FILES))
OBS= $(addprefix $(SRS_DIR), $(OBS_FILES))
HEADER=-I includes/
ARRC= ar rc
RANLIB= ranlib
RM= rm -f

${NAME}: $(OBS)
	$(ARRC) $(NAME) $(OBS)
	$(RANLIB) $(NAME)

$(SRS_DIR)%.o: $(SRS_DIR)%.c
	$(CC) $(CFLAGS)


all: obj $(NAME)
obj: $(SRCS)

clean: $(RM) $(OBS_FILES)
fclean: clean rm -f $(NAME)
re: fclean all

