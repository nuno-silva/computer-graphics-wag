#include "StaticObject.hpp"
#include <cstdio>

void StaticObject::draw()
{
    printf("StaticObject::draw();");
}
void StaticObject::update( __attribute__((unused)) GLdouble delta_t )
{
    printf("StaticObject::update();");
     // StaticObjects don't need updating. Do nothing.
 }

