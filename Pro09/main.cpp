#include <GL/glut.h>
#include <cmath>

const double PI = acos(-1.0);

void myDisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(-0.8f, -0.8f, 0.8f, 0.8f);
    
    // 画倒立三角形
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.8f, 0.8f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.8f, 0.8f);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.0f, -0.8f);
	glEnd();

    // 画紫色圆
    glColor3f(0.5f, 0.0f, 0.5f);
    glBegin(GL_POLYGON);
    int n = 100;
    float R = 0.5;
    for (int i=0; i<n; i++)
    {
        GLfloat x = R*cos(2*PI/n*i);
        GLfloat y = R*sin(2*PI/n*i);
        glVertex2f(x, y);
    }
	glEnd();


    // 画五角星	
    glColor4f(0,0,1,0);	
    glBegin(GL_LINE_LOOP); 	//以下ABCDE分别是五角星的5个顶点
    R = 0.7;
    GLfloat xA=R*cos(90*2*PI/360);   	
    GLfloat yA=R*sin(90*2*PI/360); 	
    GLfloat xB=R*cos(306*2*PI/360);	
    GLfloat yB=R*sin(306*2*PI/360); 	
    GLfloat xC=R*cos(162*2*PI/360);	
    GLfloat yC=R*sin(162*2*PI/360); 	
    GLfloat xD=R*cos(18*2*PI/360);	
    GLfloat yD=R*sin(18*2*PI/360); 	
    GLfloat xE=R*cos(234*2*PI/360);	
    GLfloat yE=R*sin(234*2*PI/360); 	
    glVertex2f(xA,yA);	
    glVertex2f(xB,yB);	
    glVertex2f(xC,yC);	
    glVertex2f(xD,yD);	
    glVertex2f(xE,yE);	
    glEnd();

	glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hello World!");
    glutDisplayFunc(&myDisplay);
    glutMainLoop();

    return 0;
}
