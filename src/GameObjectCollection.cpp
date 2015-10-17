#include "GameObjectCollection.hpp"

void GameObjectCollection::draw() {
    GameObject::draw();

    DBG_PRINT("draw()\n");

    for (auto c : _children) {
        c->draw();
    }
}

void GameObjectCollection::update( GLdouble delta_t ) {
    GameObject::update( delta_t );

    DBG_PRINT("update()\n");

    for (auto c : _children) {
        c->update( delta_t );
    }
}

void GameObjectCollection::toggleWiredSolid() {
    for (auto x : _children) {
        x->toggleWiredSolid();
    }
}

void GameObjectCollection::add( std::shared_ptr<GameObject> g) {
    DBG_PRINTF("addGameObject( %p )\n", (void*)g.get() );

    _children.push_back( g );
}
