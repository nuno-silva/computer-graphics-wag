#pragma once

// include glut.h based on platform
#ifdef __MACH__
# include <GLUT/glut.h>
#else
# include <stdlib.h>
# include <GL/glut.h>
#endif