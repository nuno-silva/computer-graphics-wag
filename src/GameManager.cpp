#include "Car.hpp"
#include "GameManager.hpp"
#include "Orange.hpp"
#include "OrthogonalCamera.hpp"
#include "Roadside.hpp"
#include "Table.hpp"


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


void GameManager::keyPressed() {}

void GameManager::onTimer() {}

void GameManager::idle() {}

void GameManager::update() {}

void GameManager::init() {
    _game_objects.add( std::make_shared<Table>( 2.0f, 0.0f, 0.0f, -1.0f ) );

    // TODO: meter roadside dentro de Table?
    _game_objects.add( std::make_shared<Roadside>( 0.92f ) );

	  _game_objects.add( std::make_shared<Car>() );

    // Oranges
    _game_objects.add( std::make_shared<Orange>(0.025f, 0.7f, 0.2f, 0.0) );
    _game_objects.add( std::make_shared<Orange>(0.025f, 0.6f, 0.6f, 0.0) );
    _game_objects.add( std::make_shared<Orange>(0.025f, -0.7f, -0.5f, 0.0) );



    _activeCamera = std::make_shared<OrthogonalCamera>(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f,2.0f);
    _activeCamera->setPosition( 0.0f, 0.0f, 1.0f );
    _cameras.push_back( _activeCamera );
}

