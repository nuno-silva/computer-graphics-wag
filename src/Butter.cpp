#include "Butter.hpp"
#include <cmath>


Butter::Butter( GLdouble x, GLdouble y, GLdouble z )
{
    setPosition( x, y, z );
#if defined DEBUG
    _axis_size = box_length * 1.5f;
#endif
    _boundingSphere._radius = box_length / 2.0f;
    _boundingSphere._initCenter = _boundingSphere._center = getPosition() + Vector3( 0.0f, 0.0f, box_height/2 + lid_height/2 );
}

void Butter::draw()
{
    glPushMatrix();
    GameObject::draw(); // translate to position
    glTranslatef( cm(0), cm(0), box_height/2 ); // butter origin is on the bottom face

    /* butter box */
    glColor3f( components3( ButterColors::box ) );
    
    {   /* white plastic */
        GLfloat amb[]={0.0f,0.0f,0.0f,1.0f};
        GLfloat diff[]={0.8f,0.8f,0.8f,1.0f};
        GLfloat spec[]={0.7f,0.7f,0.7f,1.0f};
        GLfloat shine=32.0f;
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    }
    
    glPushMatrix();
    glScalef( box_width, box_length, box_height );
    GameObject::drawCube( 1.0f ); // draw a 1x1 cube (now scaled)
    glPopMatrix();

    /* butter box lid */
    glPushMatrix();
    glTranslatef( cm(0), cm(0), box_height/2 + lid_height/2 );
    glColor3f( components3( ButterColors::lid ) );

    
    {   /* yellow plastic */
        GLfloat amb[]={0.3f,0.3f,0.0f,1.0f};
        GLfloat diff[]={0.85f,0.85f,0.0f,1.0f};
        GLfloat spec[]={0.85f,0.85f,0.5f,1.0f};
        GLfloat shine=32.0f;
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    }
    
    glScalef( lid_width, lid_length, lid_height );
    GameObject::drawCube( 1.0f );
    glPopMatrix();

    glPopMatrix();
}

void Butter::update(GLdouble delta_t) {
    DynamicObject::update(delta_t);
    if (getSpeed() < 0.0f) {
        stop();
    }
}

void Butter::processCollision(Car &car) {
    GLdouble speed = car.getSpeed() * 0.5f;
    const auto reverse = (speed / fabs(speed) < 0);

    if( fabs(speed) > cm(2) ) {
        Vector3 orientation = car.getOrientation();

        if (reverse) {
            setOrientation( orientation * -1 );
            setSpeed( speed * -1 );
        } else {
            setOrientation( orientation );
            setSpeed( speed );
        }

        setAccel( cm(-80) );
        car.stop();
    }
}
