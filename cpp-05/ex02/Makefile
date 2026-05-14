NAME		= ex02

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXXFLAGS	+= -I inc -MMD -MP

SRC			=	main.cpp						\
				src/Bureaucrat.cpp				\
				src/AForm.cpp					\
				src/ShrubberyCreationForm.hpp	\
				src/RobotomyRequestForm.hpp		\
				src/PresidentialPardonForm.hpp	\


OBJ			= $(SRC:.cpp=.o)

all:	$(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ:.o=.d)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

-include $(OBJ:.o=.d)

.PHONY: all clean fclean re