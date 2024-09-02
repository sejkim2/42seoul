NAME = ex02
CC = c++
HEADER = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Bureaucrat.cpp \
	AForm.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \
	main.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CXXFLAGS) $(SRC) -o $@

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re