#pragma once

// we need glut in almost all files...
#ifdef __MACH__
# include <GLUT/glut.h>
#else
# include <GL/glut.h>
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