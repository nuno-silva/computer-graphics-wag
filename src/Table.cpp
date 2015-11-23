#include "Table.hpp"
#include "Car.hpp"
#include <cmath>

#define TABLE_LENGTH 2.0f

Table::Table( GLdouble size ) : Table(size, 0.0f, 0.0f, 0.0f) {}

Table::Table( GLdouble size, GLdouble x, GLdouble y, GLdouble z ) : _size(size),
        _texture( TEXTURE_PATH "cloth-blue.png", 2048, 2048)
{
    setPosition(x, y, z);
    _texture.setEnabled(true);
}



void Table::draw() {
    glPushMatrix();
    //glTranslatef( cm(0), cm(0), - _size/2 ); // table origin is on the top face
    GameObject::draw();

    _texture.draw(); // load texture, set color to white

    glEnable(GL_TEXTURE_2D);
    /* Texture class should be responsible for doing this: Illya sucks :p */
    glBindTexture(GL_TEXTURE_2D, _texture.getTexId());


    //glColor3f( components3(TableColors::table) );
    {
        GLfloat amb[]={0.05f,0.05f,0.05f,1.0f};
        GLfloat diff[]={0.7f,0.7f,0.7f,1.0f};
        GLfloat spec[]={0.7f,0.7f,0.7f,1.0f};
        GLfloat shine=10.0f;
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    }

    GLdouble increment = _size / 100.0f;
    GLdouble t_inc     = 1.0f  / 100.0f;

    for( double x = -_size/2, t_x=0.0f; x < _size/2; x += increment, t_x += t_inc ) {

        glPushMatrix();
        {
            glTranslatef( x, 0.0f, 0.0f );

            glBegin(GL_QUAD_STRIP);
            glNormal3f( 0.0f, 0.0f, 1.0f );

            for( double y = -_size/2, t_y = 0.0f; y < _size/2+ increment; y += increment, t_y += t_inc ) {
                glTexCoord2f( t_x, t_y );
                glVertex3f( 0.0f, y, 0.0f );

#ifdef DEBUG
                glColor3f( x*x/_size*_size, y*y/_size*_size, x*y/_size*_size );
#endif
                glTexCoord2f( t_x + t_inc, t_y );
                glVertex3f( increment, y, 0.0f );
            }
            glEnd();
        }
        glPopMatrix();
    }

#ifdef DEBUG
    glColor3f( 1.0f, 0.5f, 0.0f );
    glutWireCube( _size );
#endif

    glDisable(GL_TEXTURE_2D);

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

    if( fabs(car.getSpeed()) >= cm(2) ) {
        car.stop();
    }
}
