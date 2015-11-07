#pragma once

#define P_CAM_FOV_Y  45

#define PI 3.14159265358979323846

#define pow2(x) pow(x, 2.0f)

// we need glut in almost all files...
#ifdef __MACH__
# include <GLUT/glut.h>
#else
# include <stdlib.h>
# include <GL/glut.h>
#endif

/* usefull unit conversions, assuming one unit is one meter */
#define mm(x) ( (x) / 1000.0f ) // millimeter to meter
#define cm(x) ( (x) / 100.0f  ) // centimeter to meter
#define dm(x) ( (x) / 10.0f   ) //  decimeter to meter
#define  m(x) ( (float) (x)   ) //      meter to meter

/* convert a color vector to 3 parameters */
#define components3(x) x[0],x[1],x[2]

/* angle conversion macros */
#define DEG_TO_RAD(d) ( (d) * PI / 180 )
#define RAD_TO_DEG(r) ( (r) / PI * 180 )

#if __GNUC__
# define ATTRIBUTE_UNUSED __attribute__((unused))
#define _STDCALL
#else
# define ATTRIBUTE_UNUSED
// Required by Windows
#define _STDCALL _stdcall
#endif


/* enables debug prints if defined; we define it in the makefile
#define DEBUG
*/

/* don't use colors for debug -- meh
#define DEBUG_NO_COLORS
*/

#if defined DEBUG
#include <cstdio>
#endif

#ifndef TIMER_PERIOD
    #define TIMER_PERIOD 10
#endif


/* terminal colors for DEBUG_COLORS */
#define KNRM  "\x1B[0;0m"
#define KRED  "\x1B[0;31m"
#define KGRN  "\x1B[0;32m"
#define KYEL  "\x1B[0;33m"
#define KBLU  "\x1B[1;34m"
#define KMAG  "\x1B[0;35m"
#define KCYN  "\x1B[0;36m"
#define KWHT  "\x1B[0;37m"
#define KGRY  "\x1B[0;90m"

/* used to print debug messages */
#ifdef DEBUG
    #ifndef DEBUG_NO_COLORS
        #define DBG_PRINTF(format, ...) printf(KYEL "%s" KGRY ":" KBLU "%d" KGRY ": " KRED format KNRM, __FILE__, __LINE__, __VA_ARGS__)
        #define DBG_PRINT(format) printf(KYEL "%s" KGRY ":" KBLU" %d" KGRY ": " KGRN format KNRM, __FILE__, __LINE__)
    #else
        #define DBG_PRINTF(format, ...) printf("%s:%d: " format, __FILE__, __LINE__, __VA_ARGS__)
        #define DBG_PRINT(format) printf("%s:%d: " format, __FILE__, __LINE__)
    #endif
#else
    #define DBG_PRINTF(format, ...)
    #define DBG_PRINT(format)
#endif
