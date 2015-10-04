#include "GameObject.hpp"


GameObject::~GameObject() {
    DBG_PRINT("~GameObject()\n");
}

void Axis3d_draw() {
    glPushMatrix();

    glBegin( GL_LINES);

    // red X axis
    glColor3f( 1.0f, 0.0f, 0.0f );
    glVertex3f( 0.0f, 0.0f, 0.0f );
    glVertex3f( 1.1f, 0.0f, 0.0f );

    // green Y axis
    glColor3f( 0.0f, 1.0f, 0.0f );
    glVertex3f( 0.0f, 0.0f, 0.0f );
    glVertex3f( 0.0f, 1.1f, 0.0f );

    // blue Z axis
    glColor3f( 0.0f, 0.0f, 1.0f );
    glVertex3f( 0.0f, 0.0f, 0.0f );
    glVertex3f( 0.0f, 0.0f, 1.1f );

    glEnd();

    glPopMatrix();
}

void GameObject::draw() {
    DBG_PRINT("draw() " KCYN "translate\n");

    // translate to the object's position
    // subclasses should call gl[Push|Pop]Matrix
    getPosition().glTranslate();

#if defined DEBUG
    Axis3d_draw();
#endif
}

void GameObject::update( __attribute__((unused)) GLdouble delta_t ) {
    DBG_PRINT("update()\n");
}
