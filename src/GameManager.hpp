#pragma once

#include "global.hpp"
#include <vector>

#include "GameObject.hpp"
#include "GameObjectCollection.hpp"
#include "Camera.hpp"

class GameManager {
    GameObjectCollection _game_objects;
    std::vector<Camera*> _cameras;
    Camera* _activeCamera;
    /* std::vector<LightSource> _light_source; */
public:
    GameManager();
    ~GameManager();

    void display();
    void reshape( GLsizei w, GLsizei h );

    void keyPressed();
    void onTimer();
    void idle();
    void update();
    void init();
};

