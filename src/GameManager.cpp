
#include "Butter.hpp"
#include "Car.hpp"
#include "CarCamera.hpp"
#include "GameManager.hpp"
#include "Orange.hpp"
#include "OrthogonalCamera.hpp"
#include "PerspectiveCamera.hpp"
#include "Roadside.hpp"
#include "Table.hpp"

#include <iostream>

GameManager::GameManager() : _game_objects(), _cameras() {
    _car = std::make_shared<Car>(1.0);
}

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
}


void GameManager::keyPressed(unsigned char key, int x, int y) {
    if (key == 'a') {
        _wired = !_wired;
    } else if (key >= '1' && key <= '3') {
        _activeCamera = _cameras[key - '1'];
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
    if (_wired) {
        _game_objects.setWired();
    } else {
        _game_objects.setSolid();
    }

    _game_objects.update(delta);
    _activeCamera->update();

    _activeCamera->computeProjectionMatrix();
    _activeCamera->computeVisualizationMatrix();

    std::cout << "Orientation: " << _car->getOrientation() << std::endl;
}

void GameManager::init() {
    // Table
    _game_objects.add(std::make_shared<Table>( m(2), m(0), m(0), m(0) ) );

    // Road
    _game_objects.add(std::make_shared<Roadside>( 0.92f ) );

    // Butters
    _game_objects.add(std::make_shared<Butter>(cm(40),  cm(57),  cm(0)));
    _game_objects.add(std::make_shared<Butter>(cm(-35), cm(-60), cm(0)));
    _game_objects.add(std::make_shared<Butter>(cm(-73), cm(0),   cm(0)));
    _game_objects.add(std::make_shared<Butter>(cm(30),  cm(20),  cm(0)));
    _game_objects.add(std::make_shared<Butter>(cm(-80), cm(70),  cm(0)));

    // Oranges
    const GLfloat orange_radius = cm(2.5);
    _game_objects.add(std::make_shared<Orange>(orange_radius, cm(70),  cm(20),  orange_radius));
    _game_objects.add(std::make_shared<Orange>(orange_radius, cm(60),  cm(60),  orange_radius));
    _game_objects.add(std::make_shared<Orange>(orange_radius, cm(-70), cm(-50), orange_radius));

    // Car
    _game_objects.add( _car );

    // Cameras
    _cameras.push_back(std::make_shared<OrthogonalCamera>(-1.2f, 1.2f, -1.2f, 1.2f, -1.2f,1.2f));
    _cameras.push_back(std::make_shared<PerspectiveCamera>(Vector3(0, -2, 2), Vector3(0, 1, 1), nullVector,
                                                           45, 2, 0.1, 10));
    _cameras.push_back(std::make_shared<CarCamera>(*_car));
    _activeCamera = _cameras[0];
}

