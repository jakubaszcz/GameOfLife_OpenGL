SRC =	main.cpp
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
