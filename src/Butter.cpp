#include "Butter.hpp"


Butter::Butter( GLdouble x, GLdouble y, GLdouble z )
{
    setPosition( x, y, z );

    _boundingSphere._radius = box_length;
    _boundingSphere._center = getPosition();
}

void Butter::draw()
{
    glPushMatrix();
    GameObject::draw(); // translate to position
    glTranslatef( cm(0), cm(0), box_height/2 ); // butter origin is on the bottom face

    /* butter box */
    glColor3f( components3( ButterColors::box ) );
    glPushMatrix();
    glScalef( box_width, box_length, box_height );
    GameObject::drawCube( 1.0f ); // draw a 1x1 cube (now scaled)
    glPopMatrix();

    /* butter box lid */
    glPushMatrix();
    glTranslatef( cm(0), cm(0), box_height/2 + lid_height/2 );
    glColor3f( components3( ButterColors::lid ) );
    glScalef( lid_width, lid_length, lid_height );
    GameObject::drawCube( 1.0f );
    glPopMatrix();

    glPopMatrix();
}

void Butter::processCollision(GameObject &go) {
    // TODO: for now it will stop/reset all objects, only stop/rest
    // if object is go.
    for (unsigned int i = 0; i < onStopCollisionListeners.size(); i++) {
        onStopCollisionListeners[i]->onStopCollision((*this));
    }

    for (unsigned int i = 0; i < onResetCollisionListeners.size(); i++) {
        onResetCollisionListeners[i]->onResetCollision((*this));
    }

}

void Butter::registerOnStopCollisonObserver(IOnCollisionObserver& obj)
{
    onStopCollisionListeners.push_back(&obj);
}

void Butter::registerOnResetCollisonObserver(IOnCollisionObserver & obj)
{
    onResetCollisionListeners.push_back(&obj);
}
