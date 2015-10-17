#pragma once

#include "global.hpp"
#include "GameObject.hpp"

#include <memory>
#include <vector>

class GameObjectCollection : public GameObject {
private:
    std::vector< std::shared_ptr<GameObject> > _children;
public:
    virtual void draw();
    virtual void update( GLdouble delta_t );
    virtual void toggleWiredSolid();
    void add ( std::shared_ptr<GameObject> g );
};
