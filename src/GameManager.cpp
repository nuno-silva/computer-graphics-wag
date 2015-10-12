
#include "Butter.hpp"
#include "Car.hpp"
#include "GameManager.hpp"
#include "Orange.hpp"
#include "OrthogonalCamera.hpp"
#include "Roadside.hpp"
#include "Table.hpp"

#include <iostream>

GameManager::GameManager() : _game_objects(), _cameras() {
    _car = std::make_shared<Car>(1.0);
}

GameManager::~GameManager() {}

/** called when the screen needs updating
 * */
void GameManager::display() {
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    _game_objects.draw();

    glFlush();
}

/** called when the window size changes
 * */
void GameManager::reshape( GLsizei w, GLsizei h ) {
    glViewport( 0, 0, w, h );

    for( auto c : _cameras ) {
        c->reshape( w, h );
    }

    _activeCamera->computeProjectionMatrix();
    _activeCamera->computeVisualizationMatrix();
}


void GameManager::keyPressed(unsigned char key, int x, int y) {
    if (key == 'a') {
        // switch object to "wireframe"
        _game_objects.invertWireframeState();
    }
}

void GameManager::specialPressed(int key, int x, int y) {
    if (key == 101) { // Up arrow
        _car->speedUp();
    } else if (key == 103) { // Down arrow
        _car->slowDown();
    }
    else if (key == GLUT_KEY_RIGHT) {
        _car->turnRight();
    }
    else if (key == GLUT_KEY_LEFT) {
        _car->turnLeft();
    }
}


void GameManager::onTimer(int value, onTimerCallback onTimer) {
    int newElapsedTime = glutGet(GLUT_ELAPSED_TIME);
    GLdouble delta = newElapsedTime - lastElapsedTime;
    lastElapsedTime = newElapsedTime;
    update(delta);
    glutPostRedisplay();
    glutTimerFunc(TIMER_PERIOD, onTimer, TIMER_PERIOD);
}

void GameManager::update(GLdouble delta) {
    // TODO: change delta
    _game_objects.update(delta);
}

void GameManager::init() {
    _game_objects.add( std::make_shared<Table>( m(2), m(0), m(0), m(0) ) );

    // TODO: meter roadside dentro de Table?
    _game_objects.add( std::make_shared<Roadside>( 0.92f ) );

    // Car
    _game_objects.add( _car );

    // Oranges
    const GLfloat orange_radius = cm(2.5);
    _game_objects.add( std::make_shared<Orange>(orange_radius, cm(70),  cm(20),  orange_radius));
    _game_objects.add( std::make_shared<Orange>(orange_radius, cm(60),  cm(60),  orange_radius));
    _game_objects.add( std::make_shared<Orange>(orange_radius, cm(-70), cm(-50), orange_radius));

    // Butter
    _game_objects.add( std::make_shared<Butter>(cm(40),  cm(57),  cm(0)));
    _game_objects.add( std::make_shared<Butter>(cm(-35), cm(-60), cm(0)));
    _game_objects.add( std::make_shared<Butter>(cm(-73), cm(0),   cm(0)));
    _game_objects.add( std::make_shared<Butter>(cm(30),  cm(20),  cm(0)));
    _game_objects.add( std::make_shared<Butter>(cm(-80), cm(70),  cm(0)));

    _activeCamera = std::make_shared<OrthogonalCamera>(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f,2.0f);
    _activeCamera->setPosition( 0.0f, 0.0f, 1.0f );
    _cameras.push_back( _activeCamera );
}

