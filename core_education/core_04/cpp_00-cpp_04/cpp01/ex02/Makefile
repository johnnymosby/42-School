NAME	=	hi
CXX		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) $(FLAGS) -o $(NAME)

.c.o:
			$(CXX) $(FLAGS) -c $< -o $(<:.c=.o)

clean:		
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all