#include <GL/glut.h>
#include "openGL.h"
#include "openGL.cpp"
#include <iostream>

using namespace std;

void myDisplay(void);
int vertexNum = 11;


Point pA, pB, pC, pD;



int main(int argc, char *argv[])
{
    init(&argc, argv, 700, 700);
    cout << "��һ���߶ε���ʼ������X~[-1.0, 1.0]  Y~[-1.0,1.0]:\n";
    cout << "X: ";  cin >> pA.x;
    cout << "Y: ";  cin >> pA.y;
    cout << "��һ���߶ε��յ�����:\n";
    cout << "X: ";  cin >> pB.x;
    cout << "Y: ";  cin >> pB.y;
    cout << "�ڶ����߶ε���ʼ������:\n";
    cout << "X: ";  cin >> pC.x;
    cout << "Y: ";  cin >> pC.y;
    cout << "�ڶ����߶ε��յ�����:\n";
    cout << "X: ";  cin >> pD.x;
    cout << "Y: ";  cin >> pD.y;

	glutDisplayFunc(&myDisplay);

	glutMainLoop();
	return 0;
}


void myDisplay(void)
{
    GLfloat R = 0.8f;

	setColor(255, 255, 255);
	line(pA, pB);
    line(pC, pD);


	glFlush();
}