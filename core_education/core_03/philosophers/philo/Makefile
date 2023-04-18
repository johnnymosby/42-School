NAME		=	philo

INC_DIR		=	./inc

INC			=	philo.h

SRC_DIR		=	./src

SRC			=	main.c initialise.c exit.c utils.c exist.c time.c
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ			=	$(SRC:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -pthread

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INC_DIR)

clean:		
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all