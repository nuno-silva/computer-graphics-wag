#include "GameManager.hpp"
#include "Roadside.hpp"

GameManager::GameManager() : _game_objects(), _cameras()
{

}

GameManager::~GameManager() {
    std::vector<GameObject*>::size_type sz = _game_objects.size();
    for( unsigned i = 0; i < sz; i++ ) {
        delete _game_objects[i];
    }
}

/** called when the screen needs updating
 * */
void GameManager::display() {
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    /* draw a green rectangle */
    glColor3f( 0.0f, 1.0f, 0.0f );
    glBegin( GL_POLYGON );
    {
        glVertex3f( -1.0f, -1.0f, 0.0f );
        glVertex3f( 0.0f, -1.0f, 0.0f );
        glVertex3f( 0.0f, 1.0f, 0.0f );
        glVertex3f( -1.0f, 1.0f, 0.0f );
    }
    glEnd();

    std::vector<GameObject*>::size_type sz = _game_objects.size();
    for( unsigned i = 0; i < sz; i++ ) {
        _game_objects[i]->draw();
    }

    // testing something
    //gluLookAt(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glutSolidCube(0.5);


    glFlush();
}

/** called when the window size changes
 * */
void GameManager::reshape( GLsizei w, GLsizei h ) {
    // FIXME
    glViewport( 0, 0, w, h );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    GLfloat ratio = (GLfloat) w / (GLfloat) h;
    if( w > h ) {
        glOrtho( -2.0f * ratio, 2.0f * ratio, -2.0f, 2.0f, -2.0f, 2.0f );
    } else {
        glOrtho( -2.0f, 2.0f, -2.0f / ratio, 2.0f / ratio, -2.0f, 2.0f );
    }

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}


void GameManager::keyPressed() {

}

void GameManager::onTimer() {

}

void GameManager::idle() {

}

void GameManager::update() {

}

void GameManager::init() {
    _game_objects.push_back( new Roadside() );
    // TODO: insert table, etc ??
}

