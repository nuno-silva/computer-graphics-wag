#include "GameObject.hpp"

void Axis3d_draw() {
    glPushMatrix();

    glBegin( GL_LINES);


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
    DBG_PRINT( "draw() " KCYN "translate\n");

    // translate to the object's position
    // subclasses should call gl[Push|Pop]Matrix
    getPosition().glTranslate();

#if defined DEBUG
    Axis3d_draw();
#endif
}

void GameObject::update(GLdouble delta_t ) {
    DBG_PRINT("update()\n");
}

void GameObject::toggleWiredSolid() {
    if (_wired) {
        setSolid();
    } else {
        setWired();
    }
}

void GameObject::setWired() {
    _wired     = true;
    drawCube   = glutWireCube;
    drawSphere = glutWireSphere;
    drawTorus  = glutWireTorus;
}

void GameObject::setSolid() {
    _wired     = false;
    drawCube   = glutSolidCube;
    drawSphere = glutSolidSphere;
    drawTorus  = glutSolidTorus;
}
