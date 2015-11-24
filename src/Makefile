CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -MMD
CXXFLAGS+= -Wno-variadic-macros -std=c++11

ifeq ($(OS),Windows_NT)
		# windows
else
		UNAME_S := $(shell uname -s)
		ifeq ($(UNAME_S),Linux)
				LDLIBS = -lGL -lGLU -lglut
				LDLIBS+= -lpng
				CXXFLAGS += -Og -ggdb
		endif
		ifeq ($(UNAME_S),Darwin)
				CXXFLAGS += -Wno-deprecated-declarations -g
				CXXFLAGS += -Wno-inconsistent-missing-override -Wno-unused-parameter -Wno-reorder
				CXXFLAGS += -I/opt/X11/include/libpng15
				LDLIBS = -framework glut -framework opengl -L/opt/X11/lib -lpng15
		endif
endif

SOURCES := $(wildcard *.cpp)
OBJS := $(SOURCES:.cpp=.o)

all: micromachines

debug: CXXFLAGS+=-DDEBUG -g
debug: all

debug_ncolor: CXXFLAGS+=-DDEBUG_NO_COLORS
debug_ncolor: debug

micromachines: $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) $(LDLIBS) -o micromachines

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)


run: micromachines
	./micromachines


clean:
	rm -f micromachines
	rm -f *.o

cleand: clean
	rm -f *.d
