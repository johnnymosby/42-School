NAME		=	ex03
CXX			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -MMD -MP -g

SRC			=	main.cpp Bureaucrat.cpp AForm.cpp \
					ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp \
					Intern.cpp
SRC_DIR		=	./src
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))

INC			=	Bureaucrat.hpp AForm.hpp definitions.hpp \
					ShrubberyCreationForm.hpp \
					RobotomyRequestForm.hpp \
					PresidentialPardonForm.hpp \
					Intern.hpp
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
			rm *_shrubbery

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
-include $(DEPS)