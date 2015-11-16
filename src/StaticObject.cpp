#include "StaticObject.hpp"
#include <cstdio>

void StaticObject::draw()
{
    getPosition().glTranslate();
}
void StaticObject::update(ATTRIBUTE_UNUSED GLdouble delta_t )
{
    // StaticObjects don't need updating. Do nothing.
}

