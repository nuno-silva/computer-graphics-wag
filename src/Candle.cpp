#include "Candle.hpp"

Candle::Candle(Vector3 pos) : Candle(pos, cm(2)) { }

Candle::Candle(GLdouble x, GLdouble y, GLdouble z) : Candle(Vector3(x,y,z)) { }

Candle::Candle(Vector3 pos, GLdouble rad) :
               _radius(rad)
{
    setPosition(pos);
}

Candle::Candle(GLdouble x, GLdouble z, GLdouble y, GLdouble rad) : Candle(Vector3(x,y,z), rad) { }

static const GLdouble top_height = cm(1.5);

void Candle::draw() 
{
    const GLint num_slices = 15;
    const GLint num_slacks = 15;

    glPushMatrix();
    StaticObject::draw(); // translate to position
    glTranslatef(0.0f, 0.0f, _radius); // Candle center is at its bottom

    glColor3f(components3(CanldeColors::skin));
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
    drawSphere(_radius, num_slices, num_slacks);
   
    
    glTranslatef(0.0f, 0.0f, _radius + 0.5 * top_height);
    glColor3f(1.0f, 1.0f, 0.9f);
    { /* pearl (white-ish) */
        GLfloat amb[]={0.525f,0.520725f,0.520725f,1.0f};
        GLfloat diff[]={1.0f,0.829f,0.829f,1.0f};
        GLfloat spec[]={0.296648f,0.296648f,0.296648f,1.0f};
        GLfloat shine=11.264f;
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    }

    glScalef(cm(0.25), cm(0.25), top_height);
    glutSolidCube(1.0f);

    glPopMatrix();
}

GLdouble Candle::getHeight() {
    return 2 * _radius + top_height;
}
