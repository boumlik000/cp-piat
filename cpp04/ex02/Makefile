NAME = abstract
CC = c++
CFLAGS= -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp \
	  Brain.cpp WrongAnimal.cpp WrongCat.cpp

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all