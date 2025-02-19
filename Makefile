SRC =	Main.cpp	\
		./src/extern/Extern.cpp	\
		./src/Display.cpp	\
		./src/Command.cpp	\
		./src/processor/Algorithm.cpp	\
		./src/processor/ChangeAlgorithmeSpeed.cpp	\
		./src/event/Event.cpp	\
		./src/event/MouseEvent.cpp	\
		./src/event/KeyBoardEvent.cpp	\
		./src/Reshape.cpp	\
		./src/Draw.cpp	\
		./src/Update.cpp	\
		./src/Window.cpp	\
		./src/Grid.cpp
NAME = GoL
CC = g++
CFLAGS = -Wall -Wextra -pedantic -O2
LDFLAGS = -lGL -lGLU -lglut

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(NAME)

re: clean all
