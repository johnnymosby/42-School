NAME	=	phonebook
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp Contact.cpp PhoneBook.cpp utils.cpp
SRC_DIR	=	./src
SRC		:=	$(addprefix $(SRC_DIR)/, $(SRC))

INC		=	Contact.hpp PhoneBook.hpp utils.hpp
INC_DIR	=	./inc

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(FLAGS) -o $(NAME)

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I $(INC_DIR)

clean:		
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all