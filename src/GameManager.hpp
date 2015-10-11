#pragma once

#include "global.hpp"
#include <vector>

#include "GameObject.hpp"
#include "GameObjectCollection.hpp"
#include "Camera.hpp"
#include "global.hpp"

typedef void(*onTimerCallback) (int);

class GameManager {
    GameObjectCollection                 _game_objects;
    std::vector<std::shared_ptr<Camera>> _cameras;
    std::shared_ptr<Camera>              _activeCamera;
    /* std::vector<LightSource> _light_source; */
public:
    GameManager();
    ~GameManager();

    void display();
    void reshape( GLsizei w, GLsizei h );
	void keyPressed(unsigned char key, int x, int y);
    void onTimer(int value, onTimerCallback onTimer);
    void update(GLdouble delta);
    void init();

public:
    unsigned int lastElapsedTime = 0;
};

