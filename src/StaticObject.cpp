#include "StaticObject.hpp"
#include <cstdio>

StaticObject::~StaticObject() {

}

void StaticObject::draw()
{
    //printf("StaticObject::draw();\n");
}
void StaticObject::update(ATTRIBUTE_UNUSED GLdouble delta_t )
{
    //printf("StaticObject::update();");
     // StaticObjects don't need updating. Do nothing.
    setWireframeState();
 }

