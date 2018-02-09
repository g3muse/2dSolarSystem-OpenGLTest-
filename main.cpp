#include <iostream>
#include <math.h>
#include <GL/glut.h>

int earthSpeed = 1;
int moonSpeed = -1;
float sunB = 1.0f;
float sunG = 1.0f;
float mercuryR = 0.5f;
float mercuryG = 0.3f;
float mercuryB = 0.3f;
float mercurySpeed = 2.6;
float venusG = 0.4f;
float venusB = 0.4f;
float venusSpeed = 1.3;
float earthR = 0.0f;
float earthG = 0.5f;
float moonR = 1.0f;
float moonG = 1.0f;
float moonB = 1.0f;
float marsG = 0.2f;
float marsB = 0.1f;
float marsSpeed = 0.8f;
float jupiterR = 0.5f;
float jupiterG = 0.3f;
float jupiterB = 0.3f;
float jupiterSpeed = 0.35f;
float saturnR = 0.5f;
float saturnG = 0.3f;
float saturnB = 0.3f;
float saturnSpeed = 0.2f;
float uranusR = 0.0f;
float uranusG = 0.2f;
float uranusSpeed = 0.03f;
float neptuneR = 0.0f;
float neptuneG = 0.2f;
float neptuneSpeed = 0.01f;
float PI = 3.14;

void myInit() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    //Sun
    glPushMatrix();
    glRotatef(earthSpeed, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(1.0f, sunG, sunB);
        glVertex2f(sin(i*PI/180)/16, cos(i*PI/180)/16);
        sunB-=0.002f;
        sunG-=0.002f;
    }
    sunB = 1.0f;
    sunG = 1.0f;
    glEnd();
    glPopMatrix();

    //Mercury
    glPushMatrix();
    glRotatef(mercurySpeed, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.1f, 0.0f, 0.0f);
    glRotatef(mercurySpeed+180, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(mercuryR, mercuryG, mercuryB);
        glVertex2f(sin(i*PI/180)/128, cos(i*PI/180)/128);
        mercuryR+=0.001f;
        mercuryG+=0.001f;
        mercuryB+=0.001f;
    }
    mercuryR = 0.5f;
    mercuryG = 0.3f;
    mercuryB = 0.3f;
    glEnd();
    glPopMatrix();

    //Venus
    glPushMatrix();
    glRotatef(venusSpeed, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.15f, 0.0f, 0.0f);
    glRotatef(venusSpeed+90, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(1.0f, venusG, venusB);
        glVertex2f(sin(i*PI/180)/120, cos(i*PI/180)/120);
        venusG+=0.001f;
        venusB+=0.001f;
    }
    venusG = 0.4f;
    venusB = 0.4f;
    glEnd();
    glPopMatrix();

    //Earth
    glPushMatrix();
    glRotatef(earthSpeed, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.23f, 0.0f, 0.0f);
    glRotatef(earthSpeed, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(earthR, earthG, 1.0f);
        glVertex2f(sin(i*PI/180)/80, cos(i*PI/180)/80);
        earthR+=0.001f;
        earthG+=0.001f;
    }
    earthR = 0.0f;
    earthG = 0.5f;
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.3f, 0.3f, 1.0f);
    for(int i=0; i <= 360; i++)
        glVertex2f(sin(i*PI/180)/80, cos(i*PI/180)/80);
    glEnd();

    //Earth's Moon
    glRotatef(moonSpeed, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.025f, 0.0f, 0.0f);
    glRotatef(moonSpeed, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(moonR, moonG, moonB);
        glVertex2f(sin(i*PI/180)/256, cos(i*PI/180)/256);
        moonR-= 0.002f;
        moonG-= 0.002f;
        moonB-= 0.002f;
    }
    moonR = 1.0f;
    moonG = 1.0f;
    moonB = 1.0f;
    glEnd();
    glPopMatrix();

    //Mars
    glPushMatrix();
    glRotatef(marsSpeed, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.33f, 0.0f, 0.0f);
    glRotatef(marsSpeed+270, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.2f, 0.1f);
    for(int i=0; i <= 360; i++) {
        glColor3f(1.0f, marsG, marsB);
        glVertex2f(sin(i*PI/180)/256, cos(i*PI/180)/256);
        marsG+=0.001f;
        marsB+=0.001f;
    }
    marsG = 0.2f;
    marsB = 0.1f;
    glEnd();

    //Mars 1st moon
    glRotatef(moonSpeed, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.01f, 0.0f, 0.0f);
    glRotatef(moonSpeed, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(moonR, moonG, moonB);
        glVertex2f(sin(i*PI/180)/512, cos(i*PI/180)/512);
        moonR-= 0.002f;
        moonG-= 0.002f;
        moonB-= 0.002f;
    }
    moonR = 1.0f;
    moonG = 1.0f;
    moonB = 1.0f;
    glEnd();
    glPopMatrix();

    //Mars 2nd moon
    glPushMatrix();
    glRotatef(marsSpeed, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.33f, 0.0f, 0.0f);
    glRotatef(moonSpeed+2, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.01f, 0.0f, 0.0f);
    glRotatef(moonSpeed+2, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(moonR, moonG, moonB);
        glVertex2f(sin(i*PI/180)/512, cos(i*PI/180)/512);
        moonR-= 0.002f;
        moonG-= 0.002f;
        moonB-= 0.002f;
    }
    moonR = 1.0f;
    moonG = 1.0f;
    moonB = 1.0f;
    glEnd();
    glPopMatrix();

    //Jupiter
    glPushMatrix();
    glRotatef(jupiterSpeed, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.43f, 0.0f, 0.0f);
    glRotatef(jupiterSpeed+180, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(jupiterR, jupiterG, jupiterB);
        glVertex2f(sin(i*PI/180)/45, cos(i*PI/180)/45);
        jupiterR+=0.001f;
        jupiterG+=0.001f;
        jupiterB+=0.001f;
    }
    jupiterR = 0.5f;
    jupiterG = 0.3f;
    jupiterB = 0.3f;
    glEnd();
    glPopMatrix();


    //Saturn
    glPushMatrix();
    glRotatef(saturnSpeed, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.55f, 0.0f, -0.5f);
    glRotatef(saturnSpeed+180, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(saturnR, saturnG, saturnB);
        glVertex3f(sin(i*PI/180)/60.0f, cos(i*PI/180)/60.0f, -0.1f);
        saturnR+=0.002f;
        saturnG+=0.001f;
        saturnB+=0.001f;
    }
    saturnR = 0.5f;
    saturnG = 0.3f;
    saturnB = 0.3f;
    glEnd();
    glPopMatrix();

    //Saturn's Ring
    glPushMatrix();
    glRotatef(saturnSpeed, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.55f, 0.0f, 0.99f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(1.0f, 1.0f, 1.0f);
        if (i <= 90) {
            glVertex3f(sin(i*PI/180)/50.0f, cos((i-45)*PI/180)/50.0f, 0.0f);
        } else if (i <= 270) {
            glVertex3f(sin(i*PI/180)/50.0f, cos((i-45)*PI/180)/50.0f, 0.1f);
        } else {
            glVertex3f(sin(i*PI/180)/50.0f, cos((i-45)*PI/180)/50.0f, 0.0f);
        }
    }
    glEnd();
    glPopMatrix();

    //Uranus
    glPushMatrix();
    glRotatef(uranusSpeed, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.65f, 0.0f, 0.0f);
    glRotatef(uranusSpeed, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(uranusR, uranusG, 1.0f);
        glVertex2f(sin(i*PI/180)/80, cos(i*PI/180)/80);
        uranusR+=0.001f;
        uranusG+=0.001f;
    }
    uranusR = 0.0f;
    uranusG = 0.2f;
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.3f, 0.3f, 1.0f);
    for(int i=0; i <= 360; i++)
        glVertex2f(sin(i*PI/180)/80, cos(i*PI/180)/80);
    glEnd();
    glPopMatrix();

    //Neptune
    glPushMatrix();
    glRotatef(neptuneSpeed-10, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.75f, 0.0f, 0.0f);
    glRotatef(neptuneSpeed, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i <= 360; i++) {
        glColor3f(neptuneR, neptuneG, 1.0f);
        glVertex2f(sin(i*PI/180)/100, cos(i*PI/180)/100);
        neptuneR+=0.001f;
        neptuneG+=0.001f;
    }
    neptuneR = 0.2f;
    neptuneG = 0.2f;
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.3f, 0.3f, 1.0f);
    for(int i=0; i <= 360; i++)
        glVertex2f(sin(i*PI/180)/100, cos(i*PI/180)/100);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void myIdle() {
    earthSpeed+=1;
    moonSpeed-=4;
    mercurySpeed+=2.6f;
    venusSpeed+=1.6f;
    marsSpeed+=0.95f;
    jupiterSpeed+=0.35f;
    saturnSpeed+=0.2f;
    uranusSpeed+=0.03f;
    neptuneSpeed+=0.01f;
    myDisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1100, 1100);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Solar System");
    myInit();
    glutDisplayFunc(myDisplay);
    glutIdleFunc(myIdle);
    glutMainLoop();
    return 0;
}
