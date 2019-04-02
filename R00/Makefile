
NAME			= ft_retro

CC				= clang++

CFLAGS			= -MD -Wall -Werror -Wextra -std=c++98 -O2

VPATH			= ./srcs:./srcs/classes

SRCS			= main.cpp AUnit.cpp Bullet.cpp Player.cpp AutoUnit.cpp
SRCS			+= play.cpp Game.cpp Enemy.cpp Sniper.cpp play_again.cpp
SRCS			+= game_cycle.cpp key_hook.cpp cloud.cpp

INCS_PATHS		= ./srcs ./srcs/classes
INCS			= $(addprefix -I,$(INCS_PATHS))

OBJS_PATH		= ./.objs/
OBJS_NAME		= $(SRCS:.cpp=.o)
OBJS			= $(addprefix $(OBJS_PATH), $(OBJS_NAME))


DEPS			= $(OBJS:.o=.d)

LIB_PATHS		=
LIBS			= $(addprefix -L,$(LIB_PATHS))

LDFLAGS			= -lncurses



all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJS_PATH)%.o: $(SRCS_PATHS)%.cpp Makefile
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

clean:
	rm -rf $(OBJS_PATH)

fclean:
	rm -rf $(OBJS_PATH)
	rm -f $(NAME)

re:
	make fclean
	make -j all

-include $(DEPS)
