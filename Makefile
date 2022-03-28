CC = g++

NAME = circlegame

LFLAGS =  -lraylib
CFLAGS = -std=c++0x -O2

OBJDIR = ./objs/
OBJECTS = $(OBJDIR)/*.o

SRC =		./src/main.cpp										\
			./src/startScreen.cpp								\
			./src/loadingScreen.cpp								\
			./src/ingame.cpp									\
			./src/drawCircle.cpp								\
			./src/drawPlayer.cpp								\
			./src/movePlayer.cpp								\
			./src/Circle.cpp									\
			./src/Player.cpp									\
			./src/textGUI.cpp									\
			./src/utils.cpp										\

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LFLAGS) $(CFLAGS) -o $(NAME)

$(OBJECTS): $(SRC)
	@$(CC) -c $(CFLAGS) $(SRC)
	@rm -rf ./objs; mkdir ./objs
	@mv *.o $(OBJDIR)

clean:
	@rm -f $(OBJECTS)
	@rm -rf ./objs

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)