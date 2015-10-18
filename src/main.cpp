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

/** spacial key is down */
void specialPressed(int key, int x, int y) {
    game.specialPressed(key, x, y, true);
}

/** spacial key is up */
void specialUp(int key, int x, int y) {
    game.specialPressed(key, x, y, false);
}

void onTimer(int value) {
    (void) value; // remove unused variable warning
    static int lastElapsedTime = 0;
    int newElapsedTime = glutGet( GLUT_ELAPSED_TIME );
    GLdouble delta = newElapsedTime - lastElapsedTime;
    lastElapsedTime = newElapsedTime;

    game.update(delta);

    glutPostRedisplay();
    glutTimerFunc(TIMER_PERIOD, onTimer, TIMER_PERIOD);
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
    glutSpecialFunc(specialPressed);
    glutSpecialUpFunc(specialUp);
    glutTimerFunc(TIMER_PERIOD, onTimer, TIMER_PERIOD);

    glutMainLoop();

    return 0;
}
