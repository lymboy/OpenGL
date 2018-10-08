#include <GL/glut.h>

#include <math.h>
const int n = 100;
const GLfloat R = 0.5f;
const GLfloat Pi = 3.1415926536f;
void myDisplay(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT); //清除颜色
	glBegin(GL_POINTS);//OpenGL要求：指定顶点的命令必须包含在glBegin函数之后，
	       //glEnd函数之前（否则指定的顶点将被忽略）。并由glBegin来指明如何使用这些点
	       //GL_POLYGON表示画多边形（由点连接成多边形）

	for(i=0; i<n; ++i)
		glVertex2f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i));

	glEnd();

	glFlush();//保证前面的OpenGL命令立即执行（而不是让它们在缓冲区中等待）

}


int main(int argc, char *argv[])
{

	glutInit(&argc, argv);//对GLUT进行初始化，这个函数必须在其它的GLUT使用之前调用一次
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //设置显示方式
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);


	glutCreateWindow("第一个OpenGL程序"); //根据前面设置的信息创建窗口。参数将被作为窗口的标题。
	glutDisplayFunc(&myDisplay); //当需要画图时，请调用myDisplay函数
	glutMainLoop(); //进行一个消息循环
	return 0;
}
