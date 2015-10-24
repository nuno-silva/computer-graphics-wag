#pragma once

#include "global.hpp"
#include <vector>

#include "Camera.hpp"
#include "Car.hpp"
#include "GameObject.hpp"
#include "GameObjectCollection.hpp"
#include "global.hpp"

typedef void(*onTimerCallback) (int);

class GameManager {
private:
    GameObjectCollection                 _game_objects;
    std::vector<std::shared_ptr<Camera>> _cameras;
    std::shared_ptr<Car>                 _car;
    std::shared_ptr<Camera>              _activeCamera;
    std::shared_ptr<Camera>              _orthogonal_cam;
    std::shared_ptr<Camera>              _perspective_cam;
    std::shared_ptr<Camera>              _car_cam;

    bool _wired = false;

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
