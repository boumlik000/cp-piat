NAME = Animal
CC = c++
CFLAGS= -Wall -Wextra -Werror -std=c++98

SRC = src/main.cpp src/Animal.cpp src/Cat.cpp src/Dog.cpp src/WrongAnimal.cpp src/WrongCat.cpp
all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all