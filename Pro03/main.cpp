#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <conio.h>

using namespace std;
const GLfloat PI = acos(-1);
int vertexNum = 0;  //顶点数

void myDisplay(void);
void init(int* argc, char** argv, GLfloat width=400, GLfloat height=400, char *title="OpenGL", GLfloat posX=100, GLfloat posY=100);
void line(GLfloat startX, GLfloat startY, GLfloat endX, GLfloat endY);
void setColor(int R, int G, int B);
 

int main(int argc, char *argv[])
{
    init(&argc, argv, 700, 700);

    cout << "请输入顶点数：";
    cin >> vertexNum;

	glutDisplayFunc(&myDisplay);

	glutMainLoop();
	return 0;
}

void init(int* argc, char** argv, GLfloat width, GLfloat height, char *title, GLfloat posX, GLfloat posY)
{
    glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(posX, posY); 
	glutInitWindowSize(width, height);
	glutCreateWindow(title);
    glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT); 
}

void myDisplay(void)
{
    GLfloat R = 0.8f;

	setColor(255, 255, 255);
	for(int i=0;i<vertexNum;i++)
	{
        GLfloat startX = R*cos(2*PI/vertexNum*i);
        GLfloat startY = R*sin(2*PI/vertexNum*i);
        //line(0.2, 0.2, -0.6, -0.6);
        for (int j=0; j<vertexNum-1; j++)
        {
            GLfloat endX = R*cos(2*PI/vertexNum*j);
            GLfloat endY = R*sin(2*PI/vertexNum*j);
            line(startX, startY, endX, endY);
        }
	}
	glFlush();
 
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