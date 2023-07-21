NAME		=	zombies
CXX			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp Zombie.cpp zombieHorde.cpp
SRC_DIR	=	./src
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))

INC			=	Zombie.hpp
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