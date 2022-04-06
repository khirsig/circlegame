CC = g++

NAME = circlegame

BREW = $(shell brew --prefix)
IFLAGS = -I $(BREW)/include
LFLAGS = -L $(BREW)/lib -lraylib
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
			./src/actionsPlayer.cpp								\
			./src/Circle.cpp									\
			./src/Player.cpp									\
			./src/PlayerModes.cpp								\
			./src/textGUI.cpp									\
			./src/utils.cpp										\
			./src/PowerUp.cpp									\

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME) $(LFLAGS) 

$(OBJECTS): $(SRC)
	@$(CC) -c $(CFLAGS) $(SRC) $(IFLAGS)
	@rm -rf ./objs; mkdir ./objs
	@mv *.o $(OBJDIR)

clean:
	@rm -f $(OBJECTS)
	@rm -rf ./objs

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

run: $(NAME)
	@./$(NAME)