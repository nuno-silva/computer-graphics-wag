CC = g++
CXXFLAGS = -Wall -Wextra -pedantic

ifeq ($(OS),Windows_NT)
		# windows
else
		UNAME_S := $(shell uname -s)
		ifeq ($(UNAME_S),Linux)
				LDLIBS = -lGL -lGLU -lglut
				CXX = g++
				CXXFLAGS += -Og
		endif
		ifeq ($(UNAME_S),Darwin)
				CXXFLAGS += -Wno-deprecated-declarations -g
				LDLIBS = -framework glut -framework opengl
		endif
endif


all: main

run: all
	./main


main: main.o


clean:
	rm -f *.o main
