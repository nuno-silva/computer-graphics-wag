#include "Table.hpp"
#include "Car.hpp"
#include <cmath>

#define TABLE_LENGTH 2.0f

Table::Table( GLdouble size ) : Table(size, 0.0f, 0.0f, 0.0f) {}

Table::Table( GLdouble size, GLdouble x, GLdouble y, GLdouble z ) : _size(size) {
    setPosition(x, y, z);
}

void Table::draw() {
    glPushMatrix();
    glTranslatef( cm(0), cm(0), - _size/2 ); // table origin is on the top face
    GameObject::draw();

    glColor3f( components3(TableColors::table) );
    glutSolidCube( _size );

#ifdef DEBUG
    glColor3f( 1.0f, 0.5f, 0.0f );
    glutWireCube( _size );
#endif
    glPopMatrix();
}

bool Table::checkCollision(GameObject &go) {
    DBG_PRINTF("checkCollision(Car %p)\n", (void*)&go);
    Vector3 pos = go.getBoundingSphereCenter();
    GLdouble sphRadius = go.getBoundingSphereRadius();
    GLdouble tableRadius = _size / 2.0f;

    GLdouble x = pos.getX();
    GLdouble y = pos.getY();
    return fabs(x) + sphRadius >= tableRadius || fabs(y) + sphRadius >= tableRadius;
}


void Table::processCollision(Car &car) {
    DBG_PRINTF("processCollision(Car %p)\n", (void*)&car);

    if( car.getSpeed() > 0.0f ) {
        car.stop();
    }
}
