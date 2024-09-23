# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 16:49:33 by irozhkov          #+#    #+#              #
#    Updated: 2024/08/18 18:43:18 by irozhkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamond

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ClapTrap.cpp DiamondTrap.cpp FragTrap.cpp main.cpp ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = ClapTrap.hpp DiamondTrap.hpp FragTrap.hpp ScavTrap.hpp

REMOVE = rm -f

GREEN = \033[0;32m
DEFAULT = \033[0m

all: $(NAME)

%.o: %.cpp $(DEPS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "---> object files $(GREEN)CREATED$(DEFAULT)\n"
	$(CC) $(OBJ) -o $(NAME)
	@echo "---> $(NAME) is $(GREEN)AVAILABLE NOW$(DEFAULT)\n"
	
clean:
	$(REMOVE) $(shell find . -name "*.o")
	@echo "---> object files $(GREEN)DELETED$(DEFAULT)\n"

fclean: clean
	$(REMOVE) $(NAME)
	@echo "---> $(NAME) $(GREEN)DELETED$(DEFAULT)\n"

re: fclean all

.PHONY: all clean fclean re
