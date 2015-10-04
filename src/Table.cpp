#include "Table.hpp"

Table::Table( GLdouble size ) : Table(size, 0.0f, 0.0f, 0.0f) {}

Table::Table( GLdouble size, GLdouble x, GLdouble y, GLdouble z ) : _size(size) {
    setPosition(x, y, z);
}

void Table::draw() {
    glPushMatrix();
    GameObject::draw();

    glColor3f( 1.0f, 1.0f, 1.0f );
    glutSolidCube( _size );

#ifdef DEBUG
    glColor3f( 1.0f, 0.5f, 0.0f );
    glutWireCube( 2.0f );
#endif
    glPopMatrix();
}
