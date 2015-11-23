#include "global.hpp"
#include "Car.hpp"
#include "DynamicObject.hpp"

#include <iostream>

Car::Car(const Vector3 &initialOrientation, GLdouble scale,
         GLdouble x, GLdouble y, GLdouble z) :
    DynamicObject::DynamicObject(initialOrientation, x, y, z), _scale(scale)
{
    setWheelsState(_wheel_inner_radius, _wheel_outer_radius, _scale);
#if defined DEBUG
    _axis_size = _bottom_length;
#endif
    _boundingSphere._radius = _bottom_length / 2.0f;
    _boundingSphere._initCenter = _boundingSphere._center = getPosition() - getOrientation() * cm(1.625);

    _leftLight = NULL;
    _rightLight = NULL;
}

Car::Car(GLdouble scale) : Car::Car(Vector3(-1.0f, 0.0f, 0.0f), scale, 0, 0, 0) {}

GLdouble Car::getScale() const {
    return _scale;
}

void Car::setOrientation(const Vector3 &v) {
    DynamicObject::setOrientation(v);
    _boundingSphere._center = getPosition() - getOrientation() * cm(1.625);
}

void Car::drawWheels() {
    for (int i = 0; i < NUM_WHEELS; i++) {
        wheels[i].draw();
    }

}

void Car::setWheelsState(GLdouble inner, GLdouble outer, GLdouble scale)
{
    wheels[0].setState(inner, outer, scale * cm(2.75), scale * cm(-1), inner + outer);
    wheels[1].setState(inner, outer, scale * cm(2.75), scale * cm(1), inner + outer);
    wheels[2].setState(inner, outer, scale * cm(0), scale * cm(-1), inner + outer);
    wheels[3].setState(inner, outer, scale * cm(0), scale * cm(1), inner + outer);
}

void Car::reset() {
    DBG_PRINT( "reset()\n" );
    stop();
    resetInitPosition();
    resetInitOrientation();
}


void Car::draw() {
    if (!_alive) {
        return;
    }

    glPushMatrix();
    {
        DynamicObject::draw(); // translate to position, rotate and draw axis

        glScalef(_scale, _scale, _scale);

        // Car lights.
        if (_leftLight != NULL) {
            _leftLight->draw();
            _rightLight->draw();
        }

        // Car bottom.
        glColor3f(components3(CarColors::bottom));
        { /* bright TURQUOISE */
            GLfloat amb[]={0.1f,0.18725f,0.41f,1.0f};
            GLfloat diff[]={0.396f,0.74151f,1.0f,1.0f};
            GLfloat spec[]={0.297254f,0.30829f,1.0f,1.0f};
            GLfloat shine=12.8f;
            glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
            glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
            glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
            glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
        }

        // Points A through H. AB stands for point A of the bottom part.
#define AB glNormal3f(cm(-0.58), cm( 0.58), cm( 0.58)); glVertex3f(cm(-1   ), cm( 1), cm(1.5));
#define BB glNormal3f(cm( 1.0), cm( 0.0), cm( 0)); glVertex3f(cm( 4.25), cm( 1), cm(1.5));
#define CB glNormal3f(cm(-0.58), cm(-0.58), cm( 0.58)); glVertex3f(cm(-1   ), cm(-1), cm(1.5));
#define DB glNormal3f(cm( 1.0), cm(0), cm( 0)); glVertex3f(cm( 4.25), cm(-1), cm(1.5));
#define EB glNormal3f(cm(-0.58), cm( 0.58), cm(-0.58)); glVertex3f(cm(-1   ), cm( 1), cm(0.5));
#define FB glNormal3f(cm( 1.0), cm( 0), cm(0)); glVertex3f(cm( 4.25), cm( 1), cm(0.5));
#define GB glNormal3f(cm(1.0), cm(0), cm(0)); glVertex3f(cm(-1   ), cm(-1), cm(0.5));
#define HB glNormal3f(cm( 0.58), cm(-0.58), cm(-0.58)); glVertex3f(cm( 4.25), cm(-1), cm(0.5));
        // Bottom.
        glBegin(GL_POLYGON); {EB FB HB GB} glEnd();
        // Top.
        glBegin(GL_POLYGON); {AB BB DB CB} glEnd();
        // Right.
        glBegin(GL_POLYGON); {AB BB FB EB} glEnd();
        // Left.
        glBegin(GL_POLYGON); {CB DB HB GB} glEnd();
        // Back.
        glBegin(GL_POLYGON); {DB BB FB HB} glEnd();
        // Front.
        glBegin(GL_POLYGON); {AB EB GB CB} glEnd();

        // Car top.
        glColor3f(components3(CarColors::top));
        { /* TURQUOISE */
            GLfloat amb[]={0.1f,0.18725f,0.1745f,1.0f};
            GLfloat diff[]={0.396f,0.74151f,0.69102f,1.0f};
            GLfloat spec[]={0.297254f,0.30829f,0.306678f,1.0f};
            GLfloat shine=12.8f;
            glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
            glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
            glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
            glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
        }
        // Points A through H. AT stands for point A of the top part.
#define AT glNormal3f(cm(0.41), cm( 0.49), cm(0.77)); glVertex3f(cm(0.75), cm( 0.75), cm(2.25));
#define BT glNormal3f(cm(0.5),  cm( 0.52), cm(0.69)); glVertex3f(cm(3.25), cm( 0.75), cm(2.25));
#define CT glNormal3f(cm(0.41), cm(-0.49), cm(0.77)); glVertex3f(cm(0.75), cm(-0.75), cm(2.25));
#define DT glNormal3f(cm(0.5),  cm(-0.52), cm(0.69)); glVertex3f(cm(3.25), cm(-0.75), cm(2.25));
#define ET glNormal3f(cm(0.41), cm( 0.49), cm(0.77)); glVertex3f(cm(0.25), cm( 0.75), cm(1.5));
#define FT glNormal3f(cm(0.5),  cm( 0.52), cm(0.69)); glVertex3f(cm(3.5),  cm( 0.75), cm(1.5));
#define GT glNormal3f(cm(0.41), cm(-0.49), cm(0.77)); glVertex3f(cm(0.25), cm(-0.75), cm(1.5));
#define HT glNormal3f(cm(0.5),  cm(-0.52), cm(0.69)); glVertex3f(cm(3.5),  cm(-0.75), cm(1.5));
        // Bottom.
        glBegin(GL_POLYGON); {ET FT HT GT} glEnd();
        // Top.
        glBegin(GL_POLYGON); {AT BT DT CT} glEnd();
        // Right.
        glBegin(GL_POLYGON); {AT BT FT ET} glEnd();
        // Left.
        glBegin(GL_POLYGON); {CT DT HT GT} glEnd();
        // Back.
        glBegin(GL_POLYGON); {DT BT FT HT} glEnd();
        // Front.
        glBegin(GL_POLYGON); {AT ET GT CT} glEnd();

        // Car front left wheel.
        glColor3f( components3(CarColors::wheels) );
        {   /* black plastic */
            GLfloat amb[]={0.02f,0.02f,0.02f,1.0f};
            GLfloat diff[]={0.01f,0.01f,0.01f,1.0f};
            GLfloat spec[]={0.4f,0.4f,0.4f,1.0f};
            GLfloat shine=10.0f;
            glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
            glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
            glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
            glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
        }
        // Points AX through HX. The I stands for interior, where the E stands for exterior.
        // FLW stands for front left wheel.
#define AIFLW glNormal3f(cm(0),     cm( 0.48), cm(0.88));  glVertex3f(cm( 0),    cm(-0.75), cm(1));
#define BIFLW glNormal3f(cm(0.62),  cm( 0.48), cm(0.62));  glVertex3f(cm( 0.35), cm(-0.75), cm(0.85));
#define CIFLW glNormal3f(cm(0.88),  cm( 0.48), cm(0));     glVertex3f(cm( 0.5),  cm(-0.75), cm(0.5));
#define DIFLW glNormal3f(cm(0.62),  cm( 0.48), cm(-0.62)); glVertex3f(cm( 0.35), cm(-0.75), cm(0.15));
#define EIFLW glNormal3f(cm(0),     cm( 0.48), cm(-0.88)); glVertex3f(cm( 0),    cm(-0.75), cm(0));
#define FIFLW glNormal3f(cm(-0.62), cm( 0.48), cm(-0.62)); glVertex3f(cm(-0.35), cm(-0.75), cm(0.15));
#define GIFLW glNormal3f(cm(-0.88), cm( 0.48), cm(0));     glVertex3f(cm(-0.5),  cm(-0.75), cm(0.5));
#define HIFLW glNormal3f(cm(-0.62), cm( 0.48), cm(0.62));  glVertex3f(cm(-0.35), cm(-0.75), cm(0.85));
#define AEFLW glNormal3f(cm(0),     cm(-0.48), cm(0.88));  glVertex3f(cm( 0),    cm(-1.25), cm(1));
#define BEFLW glNormal3f(cm(0.62),  cm(-0.48), cm(0.62));  glVertex3f(cm( 0.35), cm(-1.25), cm(0.85));
#define CEFLW glNormal3f(cm(0.88),  cm(-0.48), cm(0));     glVertex3f(cm( 0.5),  cm(-1.25), cm(0.5));
#define DEFLW glNormal3f(cm(0.62),  cm(-0.48), cm(-0.62)); glVertex3f(cm( 0.35), cm(-1.25), cm(0.15));
#define EEFLW glNormal3f(cm(0),     cm(-0.48), cm(-0.88)); glVertex3f(cm( 0),    cm(-1.25), cm(0));
#define FEFLW glNormal3f(cm(-0.62), cm(-0.48), cm(-0.62)); glVertex3f(cm(-0.35), cm(-1.25), cm(0.15));
#define GEFLW glNormal3f(cm(-0.88), cm(-0.48), cm(0));     glVertex3f(cm(-0.5),  cm(-1.25), cm(0.5));
#define HEFLW glNormal3f(cm(-0.62), cm(-0.48), cm(0.62));  glVertex3f(cm(-0.35), cm(-1.25), cm(0.85));
        // Interior.
        glBegin(GL_POLYGON); {AIFLW BIFLW CIFLW DIFLW EIFLW FIFLW GIFLW HIFLW} glEnd();
        // Exterior
        glBegin(GL_POLYGON); {AEFLW BEFLW CEFLW DEFLW EEFLW FEFLW GEFLW HEFLW} glEnd();
        // AB
        glBegin(GL_POLYGON); {AIFLW BIFLW BEFLW AEFLW} glEnd();
        // BC
        glBegin(GL_POLYGON); {BIFLW CIFLW CEFLW BEFLW} glEnd();
        // CD
        glBegin(GL_POLYGON); {CIFLW DIFLW DEFLW CEFLW} glEnd();
        // DE
        glBegin(GL_POLYGON); {DIFLW EIFLW EEFLW DEFLW} glEnd();
        // EF
        glBegin(GL_POLYGON); {EIFLW FIFLW FEFLW EEFLW} glEnd();
        // FG
        glBegin(GL_POLYGON); {FIFLW GIFLW GEFLW FEFLW} glEnd();
        // GH
        glBegin(GL_POLYGON); {GIFLW HIFLW HEFLW GEFLW} glEnd();
        // HA
        glBegin(GL_POLYGON); {HIFLW AIFLW AEFLW HEFLW} glEnd();

        // Car front right wheel.
        // Points AX through HX. The I stands for interior, where the E stands for exterior.
        // FRW stands for front right wheel.
#define AIFRW glNormal3f(cm(0),     cm( 0.48), cm(0.88));  glVertex3f(cm( 0),    cm(0.75), cm(1));
#define BIFRW glNormal3f(cm(0.62),  cm( 0.48), cm(0.62));  glVertex3f(cm( 0.35), cm(0.75), cm(0.85));
#define CIFRW glNormal3f(cm(0.88),  cm( 0.48), cm(0));     glVertex3f(cm( 0.5),  cm(0.75), cm(0.5));
#define DIFRW glNormal3f(cm(0.62),  cm( 0.48), cm(-0.62)); glVertex3f(cm( 0.35), cm(0.75), cm(0.15));
#define EIFRW glNormal3f(cm(0),     cm( 0.48), cm(-0.88)); glVertex3f(cm( 0),    cm(0.75), cm(0));
#define FIFRW glNormal3f(cm(-0.62), cm( 0.48), cm(-0.62)); glVertex3f(cm(-0.35), cm(0.75), cm(0.15));
#define GIFRW glNormal3f(cm(-0.88), cm( 0.48), cm(0));     glVertex3f(cm(-0.5),  cm(0.75), cm(0.5));
#define HIFRW glNormal3f(cm(-0.62), cm( 0.48), cm(0.62));  glVertex3f(cm(-0.35), cm(0.75), cm(0.85));
#define AEFRW glNormal3f(cm(0),     cm(-0.48), cm(0.88));  glVertex3f(cm( 0),    cm(1.25), cm(1));
#define BEFRW glNormal3f(cm(0.62),  cm(-0.48), cm(0.62));  glVertex3f(cm( 0.35), cm(1.25), cm(0.85));
#define CEFRW glNormal3f(cm(0.88),  cm(-0.48), cm(0));     glVertex3f(cm( 0.5),  cm(1.25), cm(0.5));
#define DEFRW glNormal3f(cm(0.62),  cm(-0.48), cm(-0.62)); glVertex3f(cm( 0.35), cm(1.25), cm(0.15));
#define EEFRW glNormal3f(cm(0),     cm(-0.48), cm(-0.88)); glVertex3f(cm( 0),    cm(1.25), cm(0));
#define FEFRW glNormal3f(cm(-0.62), cm(-0.48), cm(-0.62)); glVertex3f(cm(-0.35), cm(1.25), cm(0.15));
#define GEFRW glNormal3f(cm(-0.88), cm(-0.48), cm(0));     glVertex3f(cm(-0.5),  cm(1.25), cm(0.5));
#define HEFRW glNormal3f(cm(-0.62), cm(-0.48), cm(0.62));  glVertex3f(cm(-0.35), cm(1.25), cm(0.85));
        // Interior.
        glBegin(GL_POLYGON); {AIFRW BIFRW CIFRW DIFRW EIFRW FIFRW GIFRW HIFRW} glEnd();
        // Exterior
        glBegin(GL_POLYGON); {AEFRW BEFRW CEFRW DEFRW EEFRW FEFRW GEFRW HEFRW} glEnd();
        // AB
        glBegin(GL_POLYGON); {AIFRW BIFRW BEFRW AEFRW} glEnd();
        // BC
        glBegin(GL_POLYGON); {BIFRW CIFRW CEFRW BEFRW} glEnd();
        // CD
        glBegin(GL_POLYGON); {CIFRW DIFRW DEFRW CEFRW} glEnd();
        // DE
        glBegin(GL_POLYGON); {DIFRW EIFRW EEFRW DEFRW} glEnd();
        // EF
        glBegin(GL_POLYGON); {EIFRW FIFRW FEFRW EEFRW} glEnd();
        // FG
        glBegin(GL_POLYGON); {FIFRW GIFRW GEFRW FEFRW} glEnd();
        // GH
        glBegin(GL_POLYGON); {GIFRW HIFRW HEFRW GEFRW} glEnd();
        // HA
        glBegin(GL_POLYGON); {HIFRW AIFRW AEFRW HEFRW} glEnd();

        // Car back left wheel.
        // Points AX through HX. The I stands for interior, where the E stands for exterior.
        // BLW stands for back left wheel.
#define AIBLW glNormal3f(cm(0),     cm( 0.48), cm(0.88));  glVertex3f(cm(2.75), cm(-0.75), cm(1));
#define BIBLW glNormal3f(cm(0.62),  cm( 0.48), cm(0.62));  glVertex3f(cm(3.10), cm(-0.75), cm(0.85));
#define CIBLW glNormal3f(cm(0.88),  cm( 0.48), cm(0));     glVertex3f(cm(3.25), cm(-0.75), cm(0.5));
#define DIBLW glNormal3f(cm(0.62),  cm( 0.48), cm(-0.62)); glVertex3f(cm(3.10), cm(-0.75), cm(0.15));
#define EIBLW glNormal3f(cm(0),     cm( 0.48), cm(-0.88)); glVertex3f(cm(2.75), cm(-0.75), cm(0));
#define FIBLW glNormal3f(cm(-0.62), cm( 0.48), cm(-0.62)); glVertex3f(cm(2.40), cm(-0.75), cm(0.15));
#define GIBLW glNormal3f(cm(-0.88), cm( 0.48), cm(0));     glVertex3f(cm(2.25), cm(-0.75), cm(0.5));
#define HIBLW glNormal3f(cm(-0.62), cm( 0.48), cm(0.62));  glVertex3f(cm(2.40), cm(-0.75), cm(0.85));
#define AEBLW glNormal3f(cm(0),     cm(-0.48), cm(0.88));  glVertex3f(cm(2.75), cm(-1.25), cm(1));
#define BEBLW glNormal3f(cm(0.62),  cm(-0.48), cm(0.62));  glVertex3f(cm(3.10), cm(-1.25), cm(0.85));
#define CEBLW glNormal3f(cm(0.88),  cm(-0.48), cm(0));     glVertex3f(cm(3.25), cm(-1.25), cm(0.5));
#define DEBLW glNormal3f(cm(0.62),  cm(-0.48), cm(-0.62)); glVertex3f(cm(3.10), cm(-1.25), cm(0.15));
#define EEBLW glNormal3f(cm(0),     cm(-0.48), cm(-0.88)); glVertex3f(cm(2.75), cm(-1.25), cm(0));
#define FEBLW glNormal3f(cm(-0.62), cm(-0.48), cm(-0.62)); glVertex3f(cm(2.40), cm(-1.25), cm(0.15));
#define GEBLW glNormal3f(cm(-0.88), cm(-0.48), cm(0));     glVertex3f(cm(2.25), cm(-1.25), cm(0.5));
#define HEBLW glNormal3f(cm(-0.62), cm(-0.48), cm(0.62));  glVertex3f(cm(2.40), cm(-1.25), cm(0.85));
        // Interior.
        glBegin(GL_POLYGON); {AIBLW BIBLW CIBLW DIBLW EIBLW FIBLW GIBLW HIBLW} glEnd();
        // Exterior
        glBegin(GL_POLYGON); {AEBLW BEBLW CEBLW DEBLW EEBLW FEBLW GEBLW HEBLW} glEnd();
        // AB
        glBegin(GL_POLYGON); {AIBLW BIBLW BEBLW AEBLW} glEnd();
        // BC
        glBegin(GL_POLYGON); {BIBLW CIBLW CEBLW BEBLW} glEnd();
        // CD
        glBegin(GL_POLYGON); {CIBLW DIBLW DEBLW CEBLW} glEnd();
        // DE
        glBegin(GL_POLYGON); {DIBLW EIBLW EEBLW DEBLW} glEnd();
        // EF
        glBegin(GL_POLYGON); {EIBLW FIBLW FEBLW EEBLW} glEnd();
        // FG
        glBegin(GL_POLYGON); {FIBLW GIBLW GEBLW FEBLW} glEnd();
        // GH
        glBegin(GL_POLYGON); {GIBLW HIBLW HEBLW GEBLW} glEnd();
        // HA
        glBegin(GL_POLYGON); {HIBLW AIBLW AEBLW HEBLW} glEnd();

        // Car back right wheel.
        // Points AX through HX. The I stands for interior, where the E stands for exterior.
        // BRW stands for back right wheel.
#define AIBRW glNormal3f(cm(0),     cm( 0.48), cm(0.88));  glVertex3f(cm(2.75), cm(0.75), cm(1));
#define BIBRW glNormal3f(cm(0.62),  cm( 0.48), cm(0.62));  glVertex3f(cm(3.10), cm(0.75), cm(0.85));
#define CIBRW glNormal3f(cm(0.88),  cm( 0.48), cm(0));     glVertex3f(cm(3.25), cm(0.75), cm(0.5));
#define DIBRW glNormal3f(cm(0.62),  cm( 0.48), cm(-0.62)); glVertex3f(cm(3.10), cm(0.75), cm(0.15));
#define EIBRW glNormal3f(cm(0),     cm( 0.48), cm(-0.88)); glVertex3f(cm(2.75), cm(0.75), cm(0));
#define FIBRW glNormal3f(cm(-0.62), cm( 0.48), cm(-0.62)); glVertex3f(cm(2.40), cm(0.75), cm(0.15));
#define GIBRW glNormal3f(cm(-0.88), cm( 0.48), cm(0));     glVertex3f(cm(2.25), cm(0.75), cm(0.5));
#define HIBRW glNormal3f(cm(-0.62), cm( 0.48), cm(0.62));  glVertex3f(cm(2.40), cm(0.75), cm(0.85));
#define AEBRW glNormal3f(cm(0),     cm(-0.48), cm(0.88));  glVertex3f(cm(2.75), cm(1.25), cm(1));
#define BEBRW glNormal3f(cm(0.62),  cm(-0.48), cm(0.62));  glVertex3f(cm(3.10), cm(1.25), cm(0.85));
#define CEBRW glNormal3f(cm(0.88),  cm(-0.48), cm(0));     glVertex3f(cm(3.25), cm(1.25), cm(0.5));
#define DEBRW glNormal3f(cm(0.62),  cm(-0.48), cm(-0.62)); glVertex3f(cm(3.10), cm(1.25), cm(0.15));
#define EEBRW glNormal3f(cm(0),     cm(-0.48), cm(-0.88)); glVertex3f(cm(2.75), cm(1.25), cm(0));
#define FEBRW glNormal3f(cm(-0.62), cm(-0.48), cm(-0.62)); glVertex3f(cm(2.40), cm(1.25), cm(0.15));
#define GEBRW glNormal3f(cm(-0.88), cm(-0.48), cm(0));     glVertex3f(cm(2.25), cm(1.25), cm(0.5));
#define HEBRW glNormal3f(cm(-0.62), cm(-0.48), cm(0.62));  glVertex3f(cm(2.40), cm(1.25), cm(0.85));
        // Interior.
        glBegin(GL_POLYGON); {AIBRW BIBRW CIBRW DIBRW EIBRW FIBRW GIBRW HIBRW} glEnd();
        // Exterior
        glBegin(GL_POLYGON); {AEBRW BEBRW CEBRW DEBRW EEBRW FEBRW GEBRW HEBRW} glEnd();
        // AB
        glBegin(GL_POLYGON); {AIBRW BIBRW BEBRW AEBRW} glEnd();
        // BC
        glBegin(GL_POLYGON); {BIBRW CIBRW CEBRW BEBRW} glEnd();
        // CD
        glBegin(GL_POLYGON); {CIBRW DIBRW DEBRW CEBRW} glEnd();
        // DE
        glBegin(GL_POLYGON); {DIBRW EIBRW EEBRW DEBRW} glEnd();
        // EF
        glBegin(GL_POLYGON); {EIBRW FIBRW FEBRW EEBRW} glEnd();
        // FG
        glBegin(GL_POLYGON); {FIBRW GIBRW GEBRW FEBRW} glEnd();
        // GH
        glBegin(GL_POLYGON); {GIBRW HIBRW HEBRW GEBRW} glEnd();
        // HA
        glBegin(GL_POLYGON); {HIBRW AIBRW AEBRW HEBRW} glEnd();
    }
    glPopMatrix();
}

void Car::update(GLdouble delta_t) {
    DynamicObject::update( delta_t );

    for (int i = 0; i < NUM_WHEELS; i++) {
        wheels[i].update( delta_t );
        if (_wired) {
            wheels[i].setWired();
        } else {
            wheels[i].setSolid();
        }
    }
}

