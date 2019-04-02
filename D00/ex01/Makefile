# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 10:35:27 by cjacquet          #+#    #+#              #
#    Updated: 2019/03/25 18:25:00 by cjacquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

CC			= g++

CFLAGS		= -Wall -Werror -Wextra

INCLUDES	= phonebook.hpp contact.hpp

OBJS		= 	main.o\
				contact.o\
				phonebook.o

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling" $(NAME)
	@$(CC) -o $(NAME) $(OBJS)
	@echo "Compilation done!"
%.o: %.cpp
	@echo "Compiling" $<  "file..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $<

clean:
	@rm -rf $(OBJS)
	@rm -rf *.gch
	@echo "rm all objs done !"

fclean: clean
	@rm -rf $(NAME)
	@echo "rm exec done !"

re: fclean all

.PHONY: clean
