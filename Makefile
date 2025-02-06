SRC =	Main.cpp	\
		./src/extern/Extern.cpp	\
		./src/Display.cpp	\
		./src/Reshape.cpp	\
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
