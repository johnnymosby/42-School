NAME		=	world_on_fire
CXX			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -MMD -MP

SRC			=	main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
SRC_DIR		=	./src
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))

INC			=	Animal.hpp Cat.hpp Dog.hpp Brain.hpp
INC_DIR		=	./inc

OBJ		=	$(SRC:.cpp=.o)
DEPS	=	$(SRC:.cpp=.d)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) $(FLAGS) -o $(NAME)

.cpp.o:
			$(CXX) $(FLAGS) -c $< -o $(<:.cpp=.o) -I $(INC_DIR)

clean:		
			rm -f $(OBJ) $(DEPS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
-include $(DEPS)