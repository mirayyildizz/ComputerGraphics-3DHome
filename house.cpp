/**************************************
*********CSE 461 HW1*******************
*********Miray Yıldız******************
**************************************/

/* Libraries */

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415927

float camAngle = -0.45f;
float camAngle2 = 0.0f;
float camAngle3 = 0.0f;

float angle = 180.0f;
float angle2 = 0.0f;
float angle3 = 0.0f;


float zoom = 90.0;

/* Choice keyboard */

void Choices(unsigned char key, int x, int y) {
    switch (key) {
        case 'e':                                      /* If key is 'e', EXİT */
            exit(0);

         case 'w':				
            camAngle2 = camAngle2 + 0.5; 
            glutPostRedisplay();
            break;

        case 's' :

            camAngle2 = camAngle2 - 0.5; 
            glutPostRedisplay();
            break;

         case 'd':
            camAngle = camAngle + 0.5;  
            glutPostRedisplay();
            break;

         case 'a':
            camAngle = camAngle - 0.5; 
            glutPostRedisplay();
            break;

        case 't' :
            camAngle3 = camAngle3 + 0.5f; 
            glutPostRedisplay();
            break;

        case 'g':
            camAngle3 = camAngle3 - 0.5f;
            glutPostRedisplay();
            break;

        case 'r':

            angle = angle + 20.0f;
            if (angle > 360) {
                angle -= 360;
            }
            glutPostRedisplay();
            break;

        case 'l':

             angle = angle - 20.0f;
            if (angle > 360) {
                angle -= 360;
            }
            glutPostRedisplay();
            break;

        case 'q':

             angle2 = angle2 - 20.0f;
            if (angle2 > 360) {
                angle2 -= 360;
            }
            glutPostRedisplay();
            break;


        case 'p':

            angle2 = angle2 + 20.0f;
            if (angle2 > 360) {
                angle2 -= 360;
            }
            glutPostRedisplay();
            break;
        
        case 'h':

            angle3 = angle3 - 20.0f;
            if (angle3 > 360) {
                angle3 -= 360;
            }
            glutPostRedisplay();
            break;

        case 'j':
            angle3 =  angle3 + 20.0f;
            if (angle3 > 360) {
                angle3 -= 360;
            }
            glutPostRedisplay();
            break;
        
        default: 
            break;

     
    
    }

 
}

/* Inıt function */

void initRendering() {
    glEnable(GL_DEPTH_TEST);
}

 /* init to objects that changed size */

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(zoom, (double) w / (double) h, 1.0, 200.0);
}

/* The function that draws the house */

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glClearColor(1.0,1.0,0.7,1.0);                              /* Background color */

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /* Settings for translate, rotate and scale */
   
    glTranslatef(camAngle, -1.0f, 0.0f);
    glTranslatef(-1.0f, camAngle2, -2.0f);
    glTranslatef(0.0f, 0.0f, camAngle3);


    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glRotatef(angle2, 1.0f, 0.0f, 0.0f);
    glRotatef(angle3, 0.0f, 0.0f, 1.0f);

    glScalef(0.7f, 0.7f, 0.7f);
    glLineWidth(10);


   
    /* front of the house*/

    glClear (GL_COLOR_BUFFER_BIT);
    
     glColor3f (0.8, 0.7, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 0.1, 0.0);
    glVertex3f (1.0, 0.1, 0.0);
    glVertex3f (1.0, 0.575, 0.0);
    glVertex3f (0.1, 0.575, 0.0);
    glEnd();

    /* back of the house */

    glColor3f (1.0, 0.6, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 0.1, 0.5);
    glVertex3f (1.0, 0.1, 0.5);
    glVertex3f (1.0, 0.575, 0.5);
    glVertex3f (0.1, 0.575, 0.5);
    glEnd();

    /* left side of the house */

    glColor3f (1.0, 0.8, 1.5);
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 0.1, 0.5);
    glVertex3f (0.1, 0.1, 0.0);
    glVertex3f (0.1, 0.575, 0.0);
    glVertex3f (0.1, 0.575, 0.5);
    glEnd();

    /* right side of the house */

    glColor3f (1.0, 0.9, 1.9);
    glBegin(GL_POLYGON);
    glVertex3f (1.0, 0.1, 0.5);
    glVertex3f (1.0, 0.1, 0.0);
    glVertex3f (1.0, 0.575, 0.0);
    glVertex3f (1.0, 0.575, 0.5);
    glEnd();

    /* left triangle of the roof*/

    glColor3f (0.9, 0.7, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex3f (1.0, 0.575, 0.0);
    glVertex3f (1.0, 0.575, 0.5);
    glVertex3f (1.0, 0.91, 0.25);
    glEnd();

    /* right triangle of the roof */

    glColor3f (1.0, 0.5, 0.7);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.1, 0.575, 0.0);
    glVertex3f (0.1, 0.575, 0.5);
    glVertex3f (0.1, 0.91, 0.25);
    glEnd();

    /* roof */

    glColor3f (0.8, 0.5, 0.7);
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 0.575, 0.0);
    glVertex3f (1.0, 0.575, 0.0);
    glVertex3f (1.0, 0.95, 0.25);
    glVertex3f (1.0, 0.95, 0.25);
    glEnd();

    /* roof */

    glColor3f (0.8, 0.5, 0.7);
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 0.575, 0.5);
    glVertex3f (1.0, 0.575, 0.5);
    glVertex3f (1.0, 0.95, 0.25);
    glVertex3f (0.1, 0.95, 0.25);
    glEnd();

    /* door */

    glColor3f (0.0, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f (0.47, 0.105, -0.000001);
    glVertex3f (0.65, 0.105, -0.000001);
    glVertex3f (0.65, 0.46, -0.000001);
    glVertex3f (0.47, 0.46, -0.000001);
    glEnd();

    /* right window  */

    glColor3f (1.0, 1.0, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f (0.75, 0.35, -0.001);
    glVertex3f (0.90, 0.35,-0.001);
    glVertex3f (0.90, 0.50, -0.001);
    glVertex3f (0.75, 0.50, -0.001);
    glEnd();


    /* right window lines */

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.8);
    glVertex3f(0.75, 0.425, -0.01);
    glVertex3f(0.90,0.425, -0.01);
    glEnd(); 

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.8);
    glVertex3f(0.825555, 0.49876, -0.01);
    glVertex3f(0.825555,0.34, -0.01);
    glEnd(); 

    /* left window */

    glColor3f (1.0, 1.0, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f (0.20, 0.35, -0.001);
    glVertex3f (0.35, 0.35, -0.001);
    glVertex3f (0.35, 0.50, -0.001);
    glVertex3f (0.20, 0.50, -0.001);
    glEnd();

    /* left window lines */

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.8);
    glVertex3f(0.20, 0.42555, -0.01);
    glVertex3f(0.35, 0.42555, -0.01);
    glEnd(); 
    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.8);
    glVertex3f(0.27555, 0.35, -0.01);
    glVertex3f(0.27555, 0.50, -0.01);
    glEnd(); 

    /* ground */

    glColor3f(0.1f, 0.7f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex3f (-0.5, 0.1, -0.5);
    glVertex3f (1.5, 0.1, -0.5);
    glVertex3f (1.5, 0.1, 0.5);
    glVertex3f (-0.5, 0.1, 0.5);
    glEnd();




    glEnd();
    glFlush ();
    glPopMatrix();
    glutSwapBuffers();
}


/* Main fuction */
int main(int argc, char * * argv) {
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
   
    glutCreateWindow("My House");
   
    initRendering();
   
    glutDisplayFunc(drawScene);
   
    glutKeyboardFunc(Choices);
   
    glutReshapeFunc(handleResize);
   
    glutMainLoop();
   
    return 0;
}
