#include "GameObject.hpp"
#include <cstdio>

GameObject::~GameObject() {

}

void GameObject::draw() {
    printf("GameObject::draw();\n");
}

void GameObject::update( __attribute__((unused)) GLdouble delta_t ) {

}
