#include "GameObjectCollection.hpp"

GameObjectCollection::~GameObjectCollection() {
    DBG_PRINT("~GameObjectCollection()\n");
}

void GameObjectCollection::draw() {
    GameObject::draw();

    DBG_PRINT("draw()\n");

    std::vector< std::shared_ptr<GameObject> >::size_type sz = _children.size();
    for( unsigned i = 0; i < sz; i++ ) {
        _children[i]->draw();
    }
}

void GameObjectCollection::update( GLdouble delta_t ) {
    GameObject::update( delta_t );

    DBG_PRINT("update()\n");

    std::vector< std::shared_ptr<GameObject> >::size_type sz = _children.size();
    for( unsigned i = 0; i < sz; i++ ) {
        _children[i]->update( delta_t );
    }
}

void GameObjectCollection::add( std::shared_ptr<GameObject> g) {
    DBG_PRINTF("addGameObject( %p )\n", (void*)g.get() );

    _children.push_back( g );
}
