NAME = Brain
CC = c++
CFLAGS= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -std=c++98

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp\
	 WrongAnimal.cpp WrongCat.cpp Brain.cpp 
all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all