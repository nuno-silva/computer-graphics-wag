CXX = g++
CXXFLAGS = -O2 -g -Wall
LDLIBS = -lGL -lGLU -lglut

ifeq ($(OS),Windows_NT)
    # windows
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CXXFLAGS += -Wno-deprecated-declarations    
    endif
    ifeq ($(UNAME_S),Darwin)
    endif
endif


all: main

run: all
	./main


main: main.o


clean:
	rm -f *.o main
