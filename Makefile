CC = gcc

NAME = circlegame

LFLAGS = `pkg-config --libs --cflags raylib`

SDIR = ./srcs/
OBJDIR = ./objs/
LIBFT = ./libs/libft/libft.a

CFLAGS = -Wall -Werror -Wextra
OBJECTS = $(OBJDIR)/*.o

DARKBLUE	= \033[0;34m
LIGHTBLUE	= \033[0;36m
GREEN		= \033[0;32m
RED			= \033[0;31m
ORANGE		= \033[0;33m
NO_COLOR	= \033[m

SRC =	./srcs/main.c									\
		./srcs/init.c									\
		./srcs/movement.c								\
		./srcs/modes.c									\
		./srcs/text_gui.c								\
		./srcs/player.c									\
		./srcs/circles.c								\
		./srcs/collision.c								\
		./srcs/slide.c									\

all: header $(NAME)

header:
	@printf "%b" "$(DARKBLUE)"
	@echo " ________________________________________________________________________________________________________ "
	@echo "|               _       _                               _              _    _     _          _           |"
	@echo "|              (_)     (_)                             | |            | |  | |   (_)        (_)          |"
	@echo "|     _ __ ___  _ _ __  _  __ _  __ _ _ __ ___   ___   | |__  _   _   | | _| |__  _ _ __ ___ _  __ _     |"
	@echo "|    |  _   _ \| |  _ \| |/ _  |/ _  |  _   _ \ / _ \  |  _ \| | | |  | |/ /  _ \| |  __/ __| |/ _  |    |"
	@echo "|    | | | | | | | | | | | (_| | (_| | | | | | |  __/  | |_) | |_| |  |   <| | | | | |  \__ \ | (_| |    |"
	@echo "|    |_| |_| |_|_|_| |_|_|\__, |\__,_|_| |_| |_|\___|  |_.__/ \__, |  |_|\_\_| |_|_|_|  |___/_|\__, |    |"
	@echo "|                          __/ |                               __/ |                            __/ |    |"
	@echo "|                         |___/                               |___/                            |___/     |"
	@echo "|________________________________________________________________________________________________________|"
	@printf "%b" "$(LIGHTBLUE)"
	@echo "|                                                                                                        |"

header_end:
	@echo "|________________________________________________________________________________________________________|"

$(NAME):
	@make --directory=./libs/libft
	@make $(OBJECTS)
	@$(CC) $(LFLAGS) $(OBJECTS) -o $(NAME) $(LIBFT)
	@echo "|                                            Compiling completed.                                        |"
	@make header_end

$(OBJECTS): $(SRC)
	@$(CC) -c $(CFLAGS) $(SRC)
	@rm -rf ./objs; mkdir ./objs
	@mv *.o $(OBJDIR)
	@echo
	@echo "|                                       Object files created and moved.                                  |"

clean: header
	@make clean --directory=./libs/libft
	@rm -f $(OBJECTS) $(D_OBJECTS)
	@rm -rf ./objs ./debug
	@echo "|                                            Object files cleaned.                                       |"
	@make header_end

fclean: header
	@make fclean --directory=./libs/libft
	@rm -f $(NAME) $(D_NAME)
	@echo "|                                            Executeable cleaned.                                        |"
	@rm -f $(OBJECTS) $(D_OBJECTS)
	@rm -rf ./objs ./debug
	@echo "|                                            Object files cleaned.                                       |"
	@make header_end

re: header
	@make fclean --directory=./libs/libft
	@rm -f $(NAME) $(D_NAME)
	@echo "|                                            Executeable cleaned.                                        |"
	@rm -f $(OBJECTS) $(D_OBJECTS)
	@rm -rf ./objs ./debug
	@echo "|                                            Object files cleaned.                                       |"
	@make $(NAME)