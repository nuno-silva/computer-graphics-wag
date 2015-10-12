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
    GameObjectCollection                 _game_objects;
    std::vector<std::shared_ptr<Camera>> _cameras;
    std::shared_ptr<Camera>              _activeCamera;
    Car                                  _car;

    /* std::vector<LightSource> _light_source; */
public:
    GameManager();
    ~GameManager();

    void display();
    void reshape( GLsizei w, GLsizei h );
    void keyPressed(unsigned char key, int x, int y);
    void specialPressed(int key, int x, int y);
    void onTimer(int value, onTimerCallback onTimer);
    void update(GLdouble delta);
    void init();

public:
    unsigned int lastElapsedTime = 0;
};
