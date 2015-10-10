
#include "Car.hpp"
#include "GameManager.hpp"
#include "Orange.hpp"
#include "OrthogonalCamera.hpp"
#include "Roadside.hpp"
#include "Table.hpp"
#include <iostream>

#include "Butter.hpp"
#include "Car.hpp"

GameManager::GameManager() : _game_objects(), _cameras() {}

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

void GameManager::onTimer() {
    /*
    delta_t = ?
    update();
    post_display();
    timer( 10ms );
     */
}

/* use either onTimer() or idle() */

void GameManager::idle() {
    /*
    delta_t = ?
    update();
    post_display();
     */
}

void GameManager::update() {
	
}

void GameManager::init() {
    _game_objects.add( std::make_shared<Table>( m(2), m(0), m(0), m(0) ) );

    // TODO: meter roadside dentro de Table?
    _game_objects.add( std::make_shared<Roadside>( 0.92f ) );

    // Car
	  _game_objects.add( std::make_shared<Car>(0.04f, 0.04f) );

    // Oranges
    _game_objects.add( std::make_shared<Orange>(cm(2.5), cm(70),  cm(20),  0));
    _game_objects.add( std::make_shared<Orange>(cm(2.5), cm(60),  cm(60),  0));
    _game_objects.add( std::make_shared<Orange>(cm(2.5), cm(-70), cm(-50), 0));

    // Butter
    _game_objects.add( std::make_shared<Butter>(cm(40), cm(57), cm(0)));
    _game_objects.add( std::make_shared<Butter>(cm(-35), cm(-60), cm(0)));
    _game_objects.add( std::make_shared<Butter>(cm(-73), cm(0), cm(0)));
    _game_objects.add( std::make_shared<Butter>(cm(30), cm(20), cm(0)));
    _game_objects.add( std::make_shared<Butter>(cm(-80), cm(70), cm(0)));

    _activeCamera = std::make_shared<OrthogonalCamera>(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f,2.0f);
    _activeCamera->setPosition( 1.0f, 0.0f, 0.0f );
    _cameras.push_back( _activeCamera );
}

