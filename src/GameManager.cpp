
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
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    _game_objects.draw();

    #ifdef SINGLEBUF
    glFlush();
    #else
    glutSwapBuffers();
    #endif
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
    (void) x; // var is not used, but we don't want a unused-parameter warning
    (void) y; // var is not used, but we don't want a unused-parameter warning

    switch ( key ) {
        case 'a':
            _wired = !_wired;
            break;
        case '1':
            _activeCamera = _orthogonal_cam;
            break;
        case '2':
            _activeCamera = _perspective_cam;
            break;
        case '3':
            _activeCamera = _car_cam;
            break;
        default:
            DBG_PRINTF( "ignoring unknown key '%s'\n", key );
    }
}

/** handles key state changes
 * @param pressed whether the key is down or not */
void GameManager::specialPressed(int key, int x, int y, bool pressed) {
    (void) x; // var is not used, but we don't want a unused-parameter warning
    (void) y; // var is not used, but we don't want a unused-parameter warning

    switch ( key ) {
        case GLUT_KEY_UP:
            _car->setSpeedUp( pressed );
            break;
        case GLUT_KEY_DOWN:
            _car->setSlowDown( pressed );
            break;
        case GLUT_KEY_RIGHT:
            _car->setTurnRight( pressed );
            break;
        case GLUT_KEY_LEFT:
            _car->setTurnLeft( pressed );
            break;
        default:
            DBG_PRINTF( "ignoring unknown special key '%s'\n", key );
    }
}

void GameManager::update(GLdouble delta) {
    if (_wired) {
        _game_objects.setWired();
    } else {
        _game_objects.setSolid();
    }

    // NOTE: commented out since it causes the car to be reset
    // needs to be fixed before uncommenting
    _game_objects.checkCollision(*_car);

    _game_objects.update(delta);
    _activeCamera->update();
}

void GameManager::init() {
    // Table
    _game_objects.add(std::make_shared<Table>( m(2), m(0), m(0), m(0) ) );

    // Road
    _game_objects.add(std::make_shared<Roadside>( 0.92f ) );

    // Butters
    createButters();

    // Oranges
    const GLfloat orange_radius = cm(2.5);
    _game_objects.add(std::make_shared<Orange>(orange_radius, cm(70),  cm(20),  orange_radius));
    _game_objects.add(std::make_shared<Orange>(orange_radius, cm(60),  cm(60),  orange_radius));
    _game_objects.add(std::make_shared<Orange>(orange_radius, cm(-70), cm(-50), orange_radius));

    // Car
    _game_objects.add( _car );

    // Cameras
    _orthogonal_cam  = std::make_shared<OrthogonalCamera>( -1.2f, 1.2f, -1.2f, 1.2f, -1.2f, 1.2f );
    _perspective_cam = std::make_shared<PerspectiveCamera>( Vector3(0, -2, 2), Vector3(0, 1, 1), zeroVector,
                                                           P_CAM_FOV_Y, 0.1, 10 );
    _car_cam         = std::make_shared<CarCamera>(_car);

    _cameras.push_back(_orthogonal_cam);
    _cameras.push_back(_perspective_cam);
    _cameras.push_back(_car_cam);

    _activeCamera = _orthogonal_cam;
}

void GameManager::createButters()
{
    std::shared_ptr<Butter> b = std::make_shared<Butter>(cm(40), cm(57), cm(0));
    b->registerOnResetCollisonObserver(*_car);
    _game_objects.add(b);
   
    b = std::make_shared<Butter>(cm(-35), cm(-60), cm(0));
    b->registerOnResetCollisonObserver(*_car);
    _game_objects.add(b);

    b = std::make_shared<Butter>(cm(-73), cm(0), cm(0));
    b->registerOnResetCollisonObserver(*_car);
    _game_objects.add(b);

    b = std::make_shared<Butter>(cm(30), cm(20), cm(0));
    b->registerOnResetCollisonObserver(*_car);
    _game_objects.add(b);

    b = std::make_shared<Butter>(cm(-80), cm(70), cm(0));
    b->registerOnResetCollisonObserver(*_car);
    _game_objects.add(b);
    
}

