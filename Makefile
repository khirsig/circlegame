CC = g++

NAME = circlegame

LFLAGS =  -lraylib
CFLAGS = -std=c++0x -O2

OBJDIR = ./objs/
OBJECTS = $(OBJDIR)/*.o

SRC =		./src/main.cpp										\
			./src/startScreen.cpp								\
			./src/Data.cpp										\

HEADER =	./src/circlegame.hpp								\
			./src/Data.hpp										\
			config.hpp											\

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LFLAGS) $(CFLAGS) -o $(NAME)

$(OBJECTS): $(SRC) $(HEADER)
	@$(CC) -c $(CFLAGS) $(SRC)
	@rm -rf ./objs; mkdir ./objs
	@mv *.o $(OBJDIR)

clean:
	@rm -f $(OBJECTS)
	@rm -rf ./objs

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)