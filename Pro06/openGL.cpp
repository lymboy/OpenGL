#ifndef __OPENGL_CPP__
#define __OPENGL_CPP__

//#include "openGL.h"

static GLfloat WINDOW_WIDTH = 0.0f;
static GLfloat WINDOW_HEIGHT = 0.0f;

void init(int* argc, char** argv, GLfloat width, GLfloat height, char *title, GLfloat posX, GLfloat posY)
{
    WINDOW_WIDTH = width;
    glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(posX, posY); 
	glutInitWindowSize(width, height);
	glutCreateWindow(title);
    glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT); 
}

void line(Point pS, Point pE)
{
    line(pS.x, pS.y, pE.x, pE.y);
}


void line(GLfloat startX, GLfloat startY, GLfloat endX, GLfloat endY)
{
    glBegin(GL_LINES);
	glVertex2f(startX, startY);
    glVertex2f(endX, endY);
	glEnd();

	glFlush();
}

void setColor(int R, int G, int B)
{
    float r = 1.0*R/255.0;
    float g = 1.0*G/255.0;
    float b = 1.0*B/255.0;
    glColor3f(r, g, b);
}

#endif  // __OPENGL_CPP__