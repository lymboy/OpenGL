#ifndef __OPENGL_H__
#define __OPENGL_H__

#include <cmath>
#include <iostream>
//#include "openGL.cpp"

using namespace std;

const double PI = acos(-1.0);

struct Point
{
    float x;
    float y;
};

/**
 * ��ʼ������
 */
void init(int* argc, char** argv, GLfloat width=400, GLfloat height=400, char *title="OpenGL", GLfloat posX=100, GLfloat posY=100);

/**
 * ���ߺ���
 */
void line(Point pS, Point pE);

/**
 * ���ߺ���
 */
void line(GLfloat startX, GLfloat startY, GLfloat endX, GLfloat endY);

/**
 * ��ɫ���ú���������ΪRGB
 */
void setColor(int R, int G, int B);

#endif  // __OPENGL_H__