# computer-graphics-wag

A Micro Machines implementation for the Computer Graphics course - Instituto Superior Técnico, 2015

# Compiling and running on Linux
## Compiling
Make sure you have gcc, g++, openGL, GLU and GLUT installed. For instance, on Lubuntu,
```shell
sudo apt-get install g++ freeglut3-dev
```
should install all required dependencies.

You also need libpng for the lab10 version of the project:
```shell
sudo apt-get install libpng++-dev
```

To compile, just run
```shell
cd src/
make
```
## Running
To run Micro Machines:
```shell
make run
```

# Compiling and running on Windows
Good luck using Visual Studio.

# Coding style
- 4 spaces indent
- newline at end of file ([why?](http://stackoverflow.com/questions/729692/why-should-files-end-with-a-newline))
- ...
