NAME		=	losers
CXX			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp utils.cpp
SRC_DIR	=	./src
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))

INC			=	losers.hpp
INC_DIR	=	./inc

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) $(FLAGS) -o $(NAME)

.c.o:
			$(CXX) $(FLAGS) -c $< -o $(<:.c=.o) -I $(INC_DIR)

clean:		
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all