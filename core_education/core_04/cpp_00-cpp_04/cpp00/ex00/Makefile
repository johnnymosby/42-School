NAME	=	megaphone
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(FLAGS) -o $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:		
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all