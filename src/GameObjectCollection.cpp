#include "GameObjectCollection.hpp"

GameObjectCollection::~GameObjectCollection() {
    DBG_PRINT("~GameObjectCollection()\n");
}

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

void GameObjectCollection::add( std::shared_ptr<GameObject> g) {
    DBG_PRINTF("addGameObject( %p )\n", (void*)g.get() );

    _children.push_back( g );
}

void GameObjectCollection::setDrawAsWireframe(bool value)
{
	for (auto gameObj : _children) {
		gameObj->setDrawAsWireframe(value);
	}
}

void GameObjectCollection::invertWireframeState()
{
	for (auto gameObj : _children) {
		gameObj->setDrawAsWireframe(!gameObj->getDrawAsWireframe());
	}

}
