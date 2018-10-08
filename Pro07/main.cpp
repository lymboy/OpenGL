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
	glClear(GL_COLOR_BUFFER_BIT);  //�ð�ɫ�����ɫ������  
    
	glColor3f(0.0,0.0,0.0); 
    glLineWidth(1);
    //����ƽ������
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH,GL_NICEST);
	glBegin(GL_LINE_LOOP); 
    for (i=0; i<100; i++)    
	{        
		glVertex2f(R*cos(2*PI/100*i),R*sin(2*PI/100*i));   
	} 
	glEnd();
    
	//glLineWidth(3);
    //���õ�Ĵ�С
	glPointSize(5);
	//glColor3f(0.0,0.0,0.0);      //����ɫ����Ϊ��ɫ 
    // ���̶�
	for (i=0; i<12; i++) 
	{    
		if (i == 0)        
		{            
			//glLineWidth(7);            
			glColor3f(1.0,0.0,0.0);  //����0���ӵĿ̶�ʱ����ɫ����Ϊ��ɫ       
		}       
		else       
		{                  
			glColor3f(0.0,0.0,0.0);  //�����Ŀ̶ȣ���ɫ��Ϊ��ɫ       
		}   
		
		glBegin(GL_POINTS);          
		glVertex2f(TR*sin(2*PI/12*i),TR*cos(2*PI/12*i));         
		//glVertex2f(R*sin(2*PI/12*i),R*cos(2*PI/12*i));     
		glEnd(); 
	} 



    
    // ����ָ��ĳ���
	float h_Length=0.4; 
	float m_Length=0.5; 
	float s_Length=0.75;

    // ���õ�ǰָ��Ӧ��ƫ�ƵĽǶ�
	count=60; 
	s_Angle=s_current/count;
    // ÿһ������ߵĽǶ�
	count*=60; 
	m_Angle=(m_current*60+s_current)/count;
    // ÿһ��ʱ���ߵĽǶ�
    count*=12; 
	h_Angle=(h_current*60*60+m_current*60+s_current)/count; 
	
    // ��ʱ��
	glLineWidth(3); 
	glBegin(GL_LINES);
    glVertex2f(0.0f,0.0f);   
	glVertex2f(h_Length*sin(2*PI*h_Angle),h_Length*cos(2*PI*h_Angle));   
	glEnd(); 
	
    // ������
	glLineWidth(2); 
	glBegin(GL_LINES);     
	glVertex2f(0.0f,0.0f);     
	glVertex2f(m_Length*sin(2*PI*m_Angle),m_Length*cos(2*PI*m_Angle));  
	glEnd();  

    // ������
    glLineWidth(1);
	glBegin(GL_LINES);  
	glVertex2f(0.0f,0.0f);        
	glVertex2f(s_Length*sin(2*PI*s_Angle),s_Length*cos(2*PI*s_Angle)); 
	glEnd();  

    // ��Բ��
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
    // ��õ�ǰʱ��
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
