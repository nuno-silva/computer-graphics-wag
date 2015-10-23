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

bool GameObjectCollection::checkCollision(const GameObject &go) {
    for (auto & c: _children) {
        if (c->checkCollision(go)) {
            return true;
        }
    }
    return false;
}

void GameObjectCollection::processCollision(GameObject &go) {
    for (auto & c: _children) {
        c->processCollision(go);
    }
}

void GameObjectCollection::toggleWiredSolid() {
    for (auto x : _children) {
        x->toggleWiredSolid();
    }
}

void GameObjectCollection::setWired() {
    for (auto x : _children) {
        x->setWired();
    }
}

void GameObjectCollection::setSolid() {
    for (auto x : _children) {
        x->setSolid();
    }
}

void GameObjectCollection::add( std::shared_ptr<GameObject> g) {
    DBG_PRINTF("addGameObject( %p )\n", (void*)g.get() );

    _children.push_back( g );
}
