NAME		=	philo

INC_DIR		=	./inc

INC			=	philo.h

SRC_DIR		=	./src

SRC			=	main.c initialise.c create.c exit.c utils.c exist.c exist_utils.c time.c
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ			=	$(SRC:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -pthread -g #-fsanitize=thread

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