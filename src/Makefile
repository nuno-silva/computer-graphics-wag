CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic
CXXFLAGS+= -Wno-variadic-macros

ifeq ($(OS),Windows_NT)
		# windows
else
		UNAME_S := $(shell uname -s)
		ifeq ($(UNAME_S),Linux)
				LDLIBS = -lGL -lGLU -lglut
				CXXFLAGS += -Og -g
		endif
		ifeq ($(UNAME_S),Darwin)
				CXXFLAGS += -Wno-deprecated-declarations -g
				LDLIBS = -framework glut -framework opengl
		endif
endif

OBJS = main.o
OBJS += GameManager.o GameObject.o
OBJS += Camera.o OrthogonalCamera.o
OBJS += Entity.o River.o Roadside.o StaticObject.o Vector3.o

all: micromachines

debug: CXXFLAGS+=-DDEBUG -g
debug: all

debug_ncolor: CFLAGS+=-DDEBUG_NO_COLORS
debug_ncolor: debug

micromachines: $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) $(LDLIBS) -o micromachines

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)

# compile and generate dependency info
%.o: %.cpp
	$(CXX) -MMD -c $(CXXFLAGS) $*.cpp -o $*.o

run: micromachines
	./micromachines


clean:
	rm -f micromachines
	rm -f *.o

cleand: clean
	rm -f *.d
