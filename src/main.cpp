#include "global.hpp"

#define WINDOW_TITLE "Micro Machines"
#define WINDOW_SIZE 600,600


/** called when the window size changes
 * */
void reshape( int width, int height ) {
    glViewport( 0, 0, width, height );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    GLfloat ratio = (GLfloat) width / (GLfloat) height;
    if( width > height ) {
        glOrtho( -2.0f * ratio, 2.0f * ratio, -2.0f, 2.0f, -2.0f, 2.0f );
    } else {
        glOrtho( -2.0f, 2.0f, -2.0f / ratio, 2.0f / ratio, -2.0f, 2.0f );
    }

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

/** called when the screen needs updating
 * */
void display() {
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

	//gluLookAt(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidCube(0.5);

    glFlush();
}

int main( int argc, char *argv[] ) {
    glutInit( &argc, argv );

    glutInitDisplayMode( GLUT_RGBA | GLUT_SINGLE );

    glutInitWindowSize( WINDOW_SIZE );
    glutInitWindowPosition( -1, -1 );
    int window = glutCreateWindow( WINDOW_TITLE );

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
