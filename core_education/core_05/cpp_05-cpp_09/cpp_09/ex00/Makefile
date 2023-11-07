NAME		=	btc
CXX			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -MMD -MP

SRC			=	main.cpp BitcoinExchange.cpp

INC			=	BitcoinExchange.hpp

OBJ		=	$(SRC:.cpp=.o)
DEPS	=	$(SRC:.cpp=.d)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) $(FLAGS) -o $(NAME)

.cpp.o:
			$(CXX) $(FLAGS) -c $< -o $(<:.cpp=.o) -I.

clean:		
			rm -f $(OBJ) $(DEPS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
-include $(DEPS)