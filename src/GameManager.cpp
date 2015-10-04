#include "GameManager.hpp"
#include "OrthogonalCamera.hpp"
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
    /*glColor3f( 0.0f, 1.0f, 0.0f );
    glBegin( GL_POLYGON );
    {
        glVertex3f( -1.0f, -1.0f, 0.0f );
        glVertex3f( 0.0f, -1.0f, 0.0f );
        glVertex3f( 0.0f, 1.0f, 0.0f );
        glVertex3f( -1.0f, 1.0f, 0.0f );
    }
    glEnd();*/

    // testing something
    //gluLookAt(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glColor3f( 1.0f, 1.0f, 1.0f );
    glPushMatrix();
    glTranslatef( 0.0f, 0.0f, (-1.0f) );
	glutSolidCube( 2.0f );
    glColor3f( 1.0f, 1.0f, 0.0f );
	glutWireCube( 2.0f );
    glPopMatrix();


    std::vector<GameObject*>::size_type sz = _game_objects.size();
    for( unsigned i = 0; i < sz; i++ ) {
        _game_objects[i]->draw();
    }

    glFlush();
}

/** called when the window size changes
 * */
void GameManager::reshape( GLsizei w, GLsizei h ) {
    glViewport( 0, 0, w, h );

    std::vector<Camera*>::size_type sz = _cameras.size();
    for( unsigned i = 0; i < sz; i++ ) {
        _cameras[i]->reshape( w, h );
    }

    _activeCamera->computeProjectionMatrix();
    _activeCamera->computeVisualizationMatrix();
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
    _activeCamera = new OrthogonalCamera(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f,2.0f);
    _activeCamera->setPosition( 0.0f, 0.0f, 1.0f );
    _cameras.push_back( _activeCamera );
    // TODO: insert table, etc ??
}

