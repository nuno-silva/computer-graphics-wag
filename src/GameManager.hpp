#pragma once

#include "global.hpp"
#include <vector>

#include "Camera.hpp"
#include "Orange.hpp"
#include "Car.hpp"
#include "Table.hpp"
#include "GameObject.hpp"
#include "GameObjectCollection.hpp"
#include "global.hpp"

#define ORANGE_COUNT 10
#define ORANGES_UPDATE_PERIOD_MS (5.0f * 1000.0f)
#define ORANGES_SPEED_INCREMENT_MS  (cm(3.0f) / (10.0f * 1000.0f)) // 3cm per 10s

class GameManager {
private:
    GameObjectCollection                 _game_objects;
    std::vector<std::shared_ptr<Orange>> _oranges;
    std::shared_ptr<Table>               _table;
    std::vector<std::shared_ptr<Camera>> _cameras;
    std::shared_ptr<Car>                 _car;
    std::shared_ptr<Camera>              _activeCamera;
    std::shared_ptr<Camera>              _orthogonal_cam;
    std::shared_ptr<Camera>              _perspective_cam;
    std::shared_ptr<Camera>              _car_cam;

    bool _wired = false;
    bool _lighting        = false;
    bool _gouraud_shading = false;

    void updateOranges( GLdouble msSinceStart );
    /** number of milliseconds since the game was init'ed */
    GLdouble _msSinceStart = 0;
    /** number of milliseconds since the last time the oranges where updated */
    GLdouble _msSinceLastOrangeUpdate = 0;
    /* std::vector<LightSource> _light_source; */
public:
    GameManager();

    void display        (                                            );
    void reshape        (  GLsizei w,        GLsizei h               );
    void keyPressed     ( unsigned char key, int x, int y            );
    void specialPressed ( int key,           int x, int y, bool pressed );
    void update         ( GLdouble delta                             );
    void init();
    void createButters();
};
