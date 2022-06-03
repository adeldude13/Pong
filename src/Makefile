CC := clang++
cfiles := main.cpp Pong.cpp
hfiles := Pong.hpp
files := $(cfiles) $(hfiles) Makefile
out := ../bin/main
args := -O0 -ggdb3 -Wall `pkg-config sfml-all --libs --cflags` -Wextra -o $(out)

main: $(files)
	$(CC) $(args) $(cfiles) && ./$(out)

clean:
	rm $(out)
