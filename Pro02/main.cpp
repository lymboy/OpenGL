#include <GL/glut.h>

#include <math.h>
const int n = 100;
const GLfloat R = 0.5f;
const GLfloat Pi = 3.1415926536f;
void myDisplay(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT); //�����ɫ
	glBegin(GL_POINTS);//OpenGLҪ��ָ�������������������glBegin����֮��
	       //glEnd����֮ǰ������ָ���Ķ��㽫�����ԣ�������glBegin��ָ�����ʹ����Щ��
	       //GL_POLYGON��ʾ������Σ��ɵ����ӳɶ���Σ�

	for(i=0; i<n; ++i)
		glVertex2f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i));

	glEnd();

	glFlush();//��֤ǰ���OpenGL��������ִ�У��������������ڻ������еȴ���

}


int main(int argc, char *argv[])
{

	glutInit(&argc, argv);//��GLUT���г�ʼ�����������������������GLUTʹ��֮ǰ����һ��
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //������ʾ��ʽ
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);


	glutCreateWindow("��һ��OpenGL����"); //����ǰ�����õ���Ϣ�������ڡ�����������Ϊ���ڵı��⡣
	glutDisplayFunc(&myDisplay); //����Ҫ��ͼʱ�������myDisplay����
	glutMainLoop(); //����һ����Ϣѭ��
	return 0;
}
