#include <GL/glut.h>
#include <cstdio>
#include <cmath>
#include <ctime>

float h_current, m_current, s_current;
 
const double PI = acos(-1.0);


void myinit(void)  
{  
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);  
    glMatrixMode(GL_MODELVIEW);  
}


void Draw(){

    
    
	int i;

	float h_Angle,m_Angle,s_Angle,count;
	float R=0.8;    
    float TR=R-0.005;
    
    glClearColor(1.0,1.0,1.0,0.0);	
	glClear(GL_COLOR_BUFFER_BIT);  //用白色清空颜色缓冲区  
    
	glColor3f(0.0,0.0,0.0); 
    glLineWidth(1);
    //进行平滑处理　
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH,GL_NICEST);
	glBegin(GL_LINE_LOOP); 
    for (i=0; i<100; i++)    
	{        
		glVertex2f(R*cos(2*PI/100*i),R*sin(2*PI/100*i));   
	} 
	glEnd();
    
	//glLineWidth(3);
    //设置点的大小
	glPointSize(5);
	//glColor3f(0.0,0.0,0.0);      //将颜色设置为黑色 
    // 画刻度
	for (i=0; i<12; i++) 
	{    
		if (i == 0)        
		{            
			//glLineWidth(7);            
			glColor3f(1.0,0.0,0.0);  //当画0点钟的刻度时，颜色设置为红色       
		}       
		else       
		{                  
			glColor3f(0.0,0.0,0.0);  //其他的刻度，颜色都为黑色       
		}   
		
		glBegin(GL_POINTS);          
		glVertex2f(TR*sin(2*PI/12*i),TR*cos(2*PI/12*i));         
		//glVertex2f(R*sin(2*PI/12*i),R*cos(2*PI/12*i));     
		glEnd(); 
	} 



    
    // 设置指针的长度
	float h_Length=0.4; 
	float m_Length=0.5; 
	float s_Length=0.75;

    // 设置当前指针应当偏移的角度
	count=60; 
	s_Angle=s_current/count;
    // 每一秒分针走的角度
	count*=60; 
	m_Angle=(m_current*60+s_current)/count;
    // 每一秒时针走的角度
    count*=12; 
	h_Angle=(h_current*60*60+m_current*60+s_current)/count; 
	
    // 画时针
	glLineWidth(3); 
	glBegin(GL_LINES);
    glVertex2f(0.0f,0.0f);   
	glVertex2f(h_Length*sin(2*PI*h_Angle),h_Length*cos(2*PI*h_Angle));   
	glEnd(); 
	
    // 画分针
	glLineWidth(2); 
	glBegin(GL_LINES);     
	glVertex2f(0.0f,0.0f);     
	glVertex2f(m_Length*sin(2*PI*m_Angle),m_Length*cos(2*PI*m_Angle));  
	glEnd();  

    // 画秒针
    glLineWidth(1);
	glBegin(GL_LINES);  
	glVertex2f(0.0f,0.0f);        
	glVertex2f(s_Length*sin(2*PI*s_Angle),s_Length*cos(2*PI*s_Angle)); 
	glEnd();  

    // 画圆心
	glLineWidth(1);
    glBegin(GL_POLYGON); 
	for (i=0; i<100; i++)   
	{      
		glVertex2f(0.02*cos(2*PI/100*i),0.02*sin(2*PI/100*i));  
	}  
	glEnd();

	glutSwapBuffers();
}
	
void Update()
{   
	time_t rawtime;  
	struct tm *timeinfo;
    // 获得当前时间
    time( &rawtime ); 
	timeinfo = localtime( &rawtime ); 

	h_current = timeinfo->tm_hour;  
	m_current = timeinfo->tm_min;   
	s_current = timeinfo->tm_sec; 

	glutPostRedisplay();
}
	
void Reshape(int w,int h)
{    
	w=w>h?h:w;  
	glViewport(0,0,(GLsizei)w,(GLsizei)w);
}
	
int main(int argc, char *argv[])
{   
	glutInit(&argc, argv);   
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);  
	glutInitWindowSize(500, 500);   
	glutCreateWindow("HelloOpenGL");
    
	//glutReshapeFunc(&Reshape);   
	glutIdleFunc(&Update);   
	glutDisplayFunc(&Draw);  
    
	glutMainLoop();   
	return 0;
}
