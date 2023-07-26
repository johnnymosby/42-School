NAME		=	fixed_improved
CXX			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp Fixed.cpp
SRC_DIR	=	./src
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))

INC			=	Fixed.hpp
INC_DIR	=	./inc

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) $(FLAGS) -o $(NAME)

.cpp.o:
			$(CXX) $(FLAGS) -c $< -o $(<:.cpp=.o) -I $(INC_DIR)

clean:		
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re