# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 09:02:38 by tjensen           #+#    #+#              #
#    Updated: 2022/05/23 10:40:59 by khirsig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	PROJECT SPECIFIC														   #
# **************************************************************************** #

NAME			:= circlegame

CC				:= g++
CFLAGS			:= -std=c++0x -O3

SRCS			:= 		main.cpp									\
						startScreen.cpp								\
						loadingScreen.cpp							\
						loadResources.cpp							\
						ingame.cpp									\
						drawCircle.cpp								\
						drawPlayer.cpp								\
						movePlayer.cpp								\
						actionsPlayer.cpp							\
						Circle.cpp									\
						Player.cpp									\
						PlayerModes.cpp								\
						textGUI.cpp									\
						utils.cpp									\
						PowerUp.cpp									\
						Interface.cpp								\
						Elo.cpp										\
						options.cpp									\


SDIR			:= src
ODIR			:= obj
OBJS			:= $(addprefix $(ODIR)/, $(SRCS:.cpp=.o))

BREW = $(shell brew --prefix)
LDFLAGS			:= -L $(BREW)/lib -lraylib -lcurl
CFLAGS			+= -I $(BREW)/include

# **************************************************************************** #
#	RULES																	   #
# **************************************************************************** #

all:
	@make $(NAME) -j8

$(NAME): $(ODIR) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)
	@echo "\033[1;32mCirclegame compiled and linked.\033[0m"

$(ODIR)/%.o: $(SDIR)/%.cpp $(SDIR)/*.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR):
	mkdir -p $(ODIR)

clean:
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) -r *.dSYM $(SDIR)/*.dSYM
	$(RM) $(NAME)

re: fclean all
