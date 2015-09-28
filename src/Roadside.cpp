#include "Roadside.hpp"
#include <cstdio>


void Roadside::draw()
{
    printf("Roadside::draw();");
    #warning this is not working. Use std::shared_ptr instead of pointers?
    /* draw a red rectangle */
    glColor3f( 1.0f, 0.0f, 0.0f );
    glBegin( GL_POLYGON );
    {
        glVertex3f( -0.0f, -1.0f, 0.0f );
        glVertex3f( 1.0f, -1.0f, 0.0f );
        glVertex3f( 1.0f, 1.0f, 0.0f );
        glVertex3f( -0.0f, 1.0f, 0.0f );
    }
    glEnd();
}
