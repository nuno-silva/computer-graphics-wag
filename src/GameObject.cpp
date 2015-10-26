#include <cmath>

#include "Entity.hpp"
#include "GameObject.hpp"
#include "Vector3.hpp"
#include "Butter.hpp"

GameObject::GameObject() {
#if defined DEBUG
    _axis_size = 1.5f;
#endif
}

#if defined DEBUG
void GameObject::Axis3d_draw( GLdouble size ) {
    glPushMatrix();

    glBegin( GL_LINES);


    glColor3f( 1.0f, 0.0f, 0.0f );
    glVertex3f( 0.0f, 0.0f, 0.0f );
    glVertex3f( size, 0.0f, 0.0f );

    // green Y axis
    glColor3f( 0.0f, 1.0f, 0.0f );
    glVertex3f( 0.0f, 0.0f, 0.0f );
    glVertex3f( 0.0f, size, 0.0f );

    // blue Z axis
    glColor3f( 0.0f, 0.0f, 1.0f );
    glVertex3f( 0.0f, 0.0f, 0.0f );
    glVertex3f( 0.0f, 0.0f, size );

    glEnd();

    glPopMatrix();
}

void GameObject::drawBoundingSphere() {
    glPushMatrix();

    glLoadIdentity();
    glColor3f( 0.1f, 0.8f, 1.0f );
    glTranslatef( _boundingSphere._center.getX(),
                  _boundingSphere._center.getY(),
                  _boundingSphere._center.getZ() );

    glutWireSphere( _boundingSphere._radius*1.001f, 10, 10 );

    glPopMatrix();
}
#endif

void GameObject::draw() {
    //DBG_PRINT( "draw() " KCYN "translate\n");

    // translate to the object's position
    // subclasses should call gl[Push|Pop]Matrix
    getPosition().glTranslate();

#if defined DEBUG
    Axis3d_draw(_axis_size);
    drawBoundingSphere();
#endif
}

bool GameObject::checkCollision(GameObject &go) {
    // Line connecting the center of the bounding spheres.
    const Vector3 line = _boundingSphere._center - go._boundingSphere._center;
    // Square of the length of the line, to avoid computing the sqrt.
    const auto sq_distance = std::pow(line.getX(), 2) + std::pow(line.getY(), 2);

    const auto radii_sum = _boundingSphere._radius + go._boundingSphere._radius;

    /* DEBUG SPECIFIC TYPES
    if (Butter* v = dynamic_cast<Butter*>(this)) {
        std::cout << go._boundingSphere._center << std::endl;
    }
    */
    return sq_distance < std::pow(radii_sum, 2);
}


void GameObject::processCollision(Car &car) {
    (void) car; // do nothing
    DBG_PRINTF("processCollision(Car %p) ignored\n", (void*)&car);
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
