# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 10:35:27 by cjacquet          #+#    #+#              #
#    Updated: 2019/03/25 10:52:01 by cjacquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
CC		= g++
CFLAGS	= -Wall -Werror -Wextra
OBJS	= megaphone.o

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling" $(NAME)
	@$(CC) -o $(NAME) $(OBJS)
	@echo "Compilation done!"
%.o: %.cpp
	@echo "Compiling" $<  "file..."
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJS)
	@echo "rm all objs done !"

fclean: clean
	@rm -rf $(NAME)
	@echo "rm exec done !"

re: fclean all

.PHONY: clean
