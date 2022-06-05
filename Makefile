CC := clang++
src := src
cfiles := $(src)/main.cpp $(src)/Pong.cpp
hfiles := $(src)/Pong.hpp
files := $(cfiles) $(hfiles) Makefile
out := ./bin/main
args := -O0 -ggdb3 -Wall `pkg-config sfml-all --libs --cflags` -Wextra -o $(out)

main: $(files)
	$(CC) $(args) $(cfiles)

clean:
	rm $(out)
