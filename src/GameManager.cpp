
#include "Butter.hpp"
#include "Car.hpp"
#include "CarCamera.hpp"
#include "GameManager.hpp"
#include "Orange.hpp"
#include "OrthogonalCamera.hpp"
#include "PerspectiveCamera.hpp"
#include "Roadside.hpp"
#include "Table.hpp"
#include "LightSource.hpp"
#include "CandleLight.hpp"
#include "Vector4.hpp"
#include "Candle.hpp"
#include "LibpngHelper.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

GameManager::GameManager() : _game_objects(), _oranges(), _cameras() {
    _car = std::make_shared<Car>(Vector3(-1.0f, 0.0f, 0.0f), 1.0, 0.0f, -0.6f, 0.0f);
}

/** called when the screen needs updating
 * */
void GameManager::display() {
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    _game_objects.draw();

    for (auto light : _lightSources ) {
        light->draw();
    }

    _orthogonal_cam->update();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_DEPTH_TEST);

    bool lighting = glIsEnabled(GL_LIGHTING);
    glDisable(GL_LIGHTING);

    if (_gamePaused) {
        _textures.at(PAUSE_TEXTURE_POS)->draw();
    }

    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    if( lighting ) { // restore lighting state
        glEnable(GL_LIGHTING);
    }

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
        case 'c':
            _toggleCandles = ! _toggleCandles;
            break;
        case 'n':
            _isDayTime = ! _isDayTime;
            break;
        case 'l':
             if( !glIsEnabled(GL_LIGHTING) ) {
                glEnable(GL_LIGHTING);
            } else {
                glDisable(GL_LIGHTING);
            }
            break;
        case 'g':
            _gouraud_shading = ! _gouraud_shading;
            break;
        case 'h':
            _car->_leftLight-> setState(!_car->_leftLight-> getState());
            _car->_rightLight->setState(!_car->_rightLight->getState());
            break;
        case 'a':
            _wired = !_wired;
            break;
        case 's':
            togglePause();
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
            DBG_PRINTF( "ignoring unknown key '%u'\n", key );
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
            DBG_PRINTF( "ignoring unknown special key '%u'\n", key );
    }
}

void GameManager::update(GLdouble delta) {

    // if the game is paused, set delta to zero, to "freeze" the image
    delta = _gamePaused ? 0 : delta;

    /* toggle between flat shading and gouraud shading */
    if (_gouraud_shading) {
        glShadeModel( GL_SMOOTH );
    } else {
        glShadeModel( GL_FLAT );
    }

    /* turn the Sun on or off */
    _sun->setState(_isDayTime);

    /* Turn the candles on or off.
     * We use a toggle state to avoid doing this on every update. */
    if( _toggleCandles) {
        _toggleCandles = false;
        _candleLightsOn = ! _candleLightsOn;
        for (auto candleLight : _candleLights ) {
            candleLight->setState( _candleLightsOn );
        }
    }

    if (_wired) {
        _game_objects.setWired();
    } else {
        _game_objects.setSolid();
    }

    // check for and process collisions with the car
    _game_objects.processCollision(*_car);

    // check for Orange collisions with table borders
    for( auto o : _oranges ) {
        if( _table->checkCollision( *o ) ) {
            o->setActive(false);
            o->stop(); // not really needed
        }
    }

    _game_objects.update(delta);

    // update oranges if ORANGES_UPDATE_PERIOD_MS ms have passed
    _msSinceStart += delta;
    if( _msSinceStart - _msSinceLastOrangeUpdate >= ORANGES_UPDATE_PERIOD_MS ) {
        _msSinceLastOrangeUpdate = _msSinceStart;
        updateOranges( _msSinceStart );
    }

    _activeCamera->update();
}

/** returns -1 or +1 randomly */
GLdouble random_sign() {
    if( rand() % 2 == 0) {
        return 1.0f;
    }
    return -1.0f;
}

/** returns a random number in the interval [min ; max] */
GLdouble random( GLdouble min, GLdouble max ) {
    GLdouble r = (GLdouble) rand() / (GLdouble) RAND_MAX;
    r = r * (max - min) + min;
    return r;
}

void GameManager::updateOranges( GLdouble msSinceStart ) {
    DBG_PRINTF( "updateOranges( '%f' )\n", msSinceStart );
    GLdouble newSpeed = cm(3) + msSinceStart * ORANGES_SPEED_INCREMENT_MS;

    for( auto orange : _oranges ) {
        if( ! orange->isActive() ) {
            Vector3 pos = orange->getPosition();
            GLdouble newX = random_sign() * random( 0.1f, 0.81f );
            GLdouble newY = random_sign() * random( 0.11f, 0.7f );

            /* setPosition will also rotate the orange as if it moved to the new
             * position. That's not intended, but it won't hurt. */
            pos.set( newX, newY, pos.getZ() );
            orange->setPosition( pos );

            newX = random_sign() * random( 0.01f, 1.0f );
            newY = random_sign() * random( 0.01f, 1.0f );

            // TODO: make orientation random
            orange->setOrientation( newX, newY, 0.0f );

            orange->setSpeed( newSpeed );
            orange->setActive( true );
        }
    }
}

void GameManager::init() {
    // Table
    _table = std::make_shared<Table>( m(2), m(0), m(0), m(0) );
    _game_objects.add( _table );

    // Road
    _game_objects.add(std::make_shared<Roadside>( 0.92f ) );

    // Butters
    createButters();

    // Candles
    createCandles();

    createTextures();

    // Oranges
    const GLfloat orange_radius = cm(2.5);
    for( int i = 0; i < ORANGE_COUNT; i++ ) {
        auto orange = std::make_shared<Orange>(orange_radius, m(3),  m(3),  orange_radius);
        _oranges.push_back( orange );
        _game_objects.add( orange );
    }

    // Car
    _car->_leftLight  = std::make_shared<LightSource>(GL_LIGHT6);
    _car->_rightLight = std::make_shared<LightSource>(GL_LIGHT7);

    _car-> _leftLight->setAttenuation(1, 1, 20);
    _car->_leftLight->setAmbient( Vector4( 0.3f, 0.3f, 0.3f, 1.0f ) );
    _car->_leftLight->setDiffuse( Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    _car->_leftLight->setSpecular(Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    _car->_leftLight->setCutoff( 30.0f );
    _car->_leftLight->setExponent( 1.5f );

    _car->_rightLight->setAttenuation(1, 1, 20);
    _car->_rightLight->setAmbient( Vector4( 0.3f, 0.3f, 0.3f, 1.0f ) );
    _car->_rightLight->setDiffuse( Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    _car->_rightLight->setSpecular(Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    _car->_rightLight->setCutoff( 30.0f );
    _car->_rightLight->setExponent( 1.5f );


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

    // initiate random seed
    srand (time(NULL));

    // place the first oranges
    updateOranges( 0 );

    // create the Sun
    _sun = std::make_shared<LightSource> ( GL_LIGHT0 );
    _sun->setPosition( Vector3( 1.0f, 1.0f, 1.0f ) );
    _sun->setDirection( Vector3( 0.0f, 0.0f, 0.0f ) );
    _sun->setAmbient( Vector4( 0.4f, 0.4f, 0.4f, 1.0f ) );
    _sun->setDiffuse( Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    _sun->setSpecular(Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    _sun->setCutoff( 180.0f );
    _sun->setExponent( 0.0f );
    _sun->setState( true );
    _lightSources.push_back( _sun );

    // testing spot light
    /*auto _spot = std::make_shared<LightSource> ( GL_LIGHT12 );
    _spot->setPosition( Vector3( cm(10), cm(50), cm(10) ) );
    _spot->setDirection( Vector3( 0.0f, 0.0f, -1.0f ) );
    _spot->setAmbient( Vector4( 0.2f, 0.2f, 0.2f, 1.0f ) );
    _spot->setDiffuse( Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    _spot->setSpecular(Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    _spot->setCutoff( 90.0f );
    _spot->setExponent( 2.0f );
    _spot->setState( true );
    _lightSources.push_back( _spot );*/


}

void GameManager::createButters()
{
    std::shared_ptr<Butter> b = std::make_shared<Butter>(cm(40), cm(57), cm(0));
    _game_objects.add(b);

    b = std::make_shared<Butter>(cm(-35), cm(-60), cm(0));
    _game_objects.add(b);

    b = std::make_shared<Butter>(cm(-73), cm(0), cm(0));
    _game_objects.add(b);

    b = std::make_shared<Butter>(cm(30), cm(20), cm(0));
    _game_objects.add(b);

    b = std::make_shared<Butter>(cm(-80), cm(70), cm(0));
    _game_objects.add(b);

}

void GameManager::createCandle( Vector3 pos , GLenum lightNum) {
    auto _candle = std::make_shared<Candle>( pos );
    _game_objects.add(_candle);

    pos = pos + Vector3( 0.0f, 0.0f, _candle->getHeight() );
    auto _spot = std::make_shared<CandleLight> ( pos, lightNum );
    _lightSources.push_back( _spot );
    _candleLights.push_back( _spot );
}

void GameManager::togglePause()
{
    _gamePaused = !_gamePaused;
    _textures.at(PAUSE_TEXTURE_POS)->toggleEnabled();


}

void GameManager::createTextures()
{
    char* pauseFileName = TEXTURE_PATH "pause.png";
    _textures.push_back(std::make_shared<PauseTexture>(pauseFileName, 1024, 256));
}


void GameManager::createCandles()
{
	createCandle( Vector3 ( cm(63), cm(-63), 0.0f ),  GL_LIGHT1 );
	createCandle( Vector3 ( cm(-5), cm(-40), 0.0f ),  GL_LIGHT2 );
	createCandle( Vector3 ( cm(-65), cm(63), 0.0f ),  GL_LIGHT3 );
	createCandle( Vector3 ( cm(-80), cm(-60), 0.0f ), GL_LIGHT4 );
	createCandle( Vector3 ( cm(80), cm(60), 0.0f ),   GL_LIGHT5 );
}

