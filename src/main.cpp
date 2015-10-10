#include "global.hpp"
#include "GameManager.hpp"

#define WINDOW_TITLE "Micro Machines"
#define WINDOW_SIZE 600,600

static GameManager game;

/** called when the window size changes
 * */
void reshape( int width, int height ) {
    game.reshape( width, height );
}

/** called when the screen needs updating
 * */
void display() {
    game.display(); // this calls flush
}

/** called when a key is pressed
* */
void keyPressed(unsigned char key, int x, int y) {
    game.keyPressed(key, x, y);
}

int main( int argc, char *argv[] ) {
    glutInit( &argc, argv );

    glutInitDisplayMode( GLUT_RGBA | GLUT_SINGLE );

    glutInitWindowSize( WINDOW_SIZE );
    glutInitWindowPosition( -1, -1 );

    glutCreateWindow( WINDOW_TITLE );


    game.init();

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);

    glutMainLoop();

    return 0;
}
