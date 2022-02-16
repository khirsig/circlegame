CC = gcc

NAME = circlegame

LIBPATH = ./libs/libft/libft.a
LFLAGS =  -lraylib
CFLAGS = -Wall -Werror -Wextra -O2

OBJDIR = ./objs/
OBJECTS = $(OBJDIR)/*.o

SRC =	./srcs/main.c									\
		./srcs/debug.c									\
		./srcs/init.c									\
		./srcs/movement.c								\
		./srcs/modes.c									\
		./srcs/text_gui.c								\
		./srcs/player.c									\
		./srcs/circles.c								\
		./srcs/triangles.c								\
		./srcs/collision.c								\
		./srcs/slide.c									\
		./srcs/time.c									\
		./srcs/warp.c									\
		./srcs/window.c									\

all: $(NAME)

$(NAME): $(OBJECTS)
	@make --directory=./libs/libft
	@$(CC) $(OBJECTS) $(LFLAGS) $(CFLAGS) -o $(NAME) $(LIBPATH)

$(OBJECTS): $(SRC)
	@$(CC) -c $(CFLAGS) $(SRC)
	@rm -rf ./objs; mkdir ./objs
	@mv *.o $(OBJDIR)

clean:
	@make clean --directory=./libs/libft
	@rm -f $(OBJECTS)
	@rm -rf ./objs

fclean: clean
	@make fclean --directory=./libs/libft
	@rm -rf $(NAME)

re: fclean $(NAME)