NAME = ScavTrap
CC = c++
CFLAGS= -Wall -Wextra -Werror -std=c++98

SRC = $(shell find '.' -name "*.cpp") # main.cpp ClapTrap.cpp ScavTrap.cpp

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all