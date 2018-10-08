#include<gl/glut.h>
#include<math.h>
#include<windows.h>
#include<algorithm>
using namespace std;
const double PI = acos(-1.0);
#define getColor(a) (a/255.0)
int cnt;        //������
void drawCircle(float x, float y, float r)      //��Բ
{
    int n = 100;
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
    {
        glVertex2f(r*cos(i * 2 * PI / n)+x, r*sin(i * 2 * PI / n)+y);
    }
    glEnd();
}
void graphy1()      //���񵳵���
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(getColor(14), getColor(0), getColor(140));        //��Χ����Բ
    drawCircle(0, 0, 0.7);

    glColor3f(1, 1, 1);     //��ɫ�����
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);
    for (int i = 0; i <= 24; i++)
    { 
        // �ж���ż��
        if (i & 1)
            glVertex2f(0.4*sin(i * 2 * PI / 24), 0.4*cos(i * 2 * PI / 24));
        else
            glVertex2f(0.68*sin(i * 2 * PI / 24), 0.68*cos(i * 2 * PI / 24));
    }
    glEnd();

    glColor3f(getColor(14), getColor(0), getColor(140));        //��ɫԲ
    drawCircle(0, 0, 0.36);

    glColor3f(1, 1, 1);     //��ɫԲ
    drawCircle(0, 0, 0.32);

    glFlush();
}

void graphy2()      //�������Ż�
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0);     //��Χ��ɫԲ
    drawCircle(0, 0, 0.7);

    glColor3f(1, 0, 0);     //��ɫԲ
    drawCircle(0, 0, 0.65);

    glColor3f(1, 1, 0);     //����ǣ���䣩
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);
    for (i = 0; i <= 10; i++)
    {
        if (i&1)
            glVertex2f(0.25*sin(i * 2 * PI / 10), 0.25*cos(i * 2 * PI / 10));
        else
            glVertex2f(0.65*sin(i * 2 * PI / 10), 0.65*cos(i * 2 * PI / 10));
    }
    glEnd();

    glColor3f(0, 0, 0);     //���������
    for (i = 0; i <= 10; i++)
    {
        float p1_x, p1_y, p2_x, p2_y;
        if (i & 1)
        {
            p1_x = 0.25*sin(i * 2 * PI / 10);
            p1_y = 0.25*cos(i * 2 * PI / 10);
            p2_x = 0.65*sin((i + 1) * 2 * PI / 10);
            p2_y = 0.65*cos((i + 1) * 2 * PI / 10);
        }
        else
        {
            p1_x = 0.65*sin(i * 2 * PI / 10);
            p1_y = 0.65*cos(i * 2 * PI / 10);
            p2_x = 0.25*sin((i+1) * 2 * PI / 10);
            p2_y = 0.25*cos((i+1) * 2 * PI / 10);
        }

        glBegin(GL_LINES);
        glVertex2f(0, 0); glVertex2f(p1_x, p1_y);
        glVertex2f(0, 0); glVertex2f(p2_x, p2_y);
        glVertex2f(p1_x, p1_y); glVertex2f(p2_x, p2_y);
        glEnd();
    }

    glFlush();
}

void graphy3()      //�����
{
    glClear(GL_COLOR_BUFFER_BIT);

    const float r = 0.7;
    const float hr = r / 2.0;
    for (int i = 0; i < cnt; i++)
    {
        float p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;
        p1_x = r*sin(i * 2 * PI / cnt);
        p1_y = r*cos(i * 2 * PI / cnt);
        p2_x = r*sin((i+1) * 2 * PI / cnt);
        p2_y = r*cos((i+1) * 2 * PI / cnt);
        p3_x = hr*sin((i<<1|1) * PI / cnt);
        p3_y = hr*cos((i<<1|1) * PI / cnt);

        glBegin(GL_TRIANGLES);      //���
        glColor3f(1, 0, 1);
        glVertex2f(p1_x, p1_y);
        glVertex2f(p2_x, p2_y);
        glVertex2f(p3_x, p3_y);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1, 1, 1);
        glVertex2f(0, 0);
        glVertex2f(p1_x, p1_y);
        glVertex2f(p3_x, p3_y);
        glVertex2f(p2_x, p2_y);
        glEnd();

        glBegin(GL_LINES);      //�߽�����
        glColor3f(1, 0, 0);
        glVertex2f(0, 0); glVertex2f(p1_x, p1_y);
        glVertex2f(0, 0); glVertex2f(p2_x, p2_y);
        glColor3f(0, 0, 0);
        glVertex2f(0, 0); glVertex2f(p3_x, p3_y);
        glVertex2f(p2_x, p2_y); glVertex2f(p1_x, p1_y);
        glVertex2f(p3_x, p3_y); glVertex2f(p1_x, p1_y);
        glVertex2f(p3_x, p3_y); glVertex2f(p2_x, p2_y);
        glEnd();
    }

    glFlush();
}

void initWindow(int &argc, char *argv[], int width, int height, char *title)    //��ʼ������ʾ����Ļ����
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition((GetSystemMetrics(SM_CXSCREEN) - width) >> 1, (GetSystemMetrics(SM_CYSCREEN) - height) >> 1);       //ָ������λ��
    glutInitWindowSize(width, height);       //ָ�����ڴ�С
    glutCreateWindow(title);

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);      //������ɫ����ģʽ��Ĭ��ΪGL_SMOOTH�����䣩
}
void welcome()
{
    puts("\n\t˵����\tͼ����ʽѡ��1�����ƹ��񵳵��գ�");
    puts("\t\tͼ����ʽ��Ϊ1������������5�����ƹ������Żգ�");
    puts("\t\t������ƻ���ͼ����");
    printf("\n������ͼ����ʽ(1�����񵳵��գ����಻Ϊ1)��");
}
int main(int argc, char *argv[])
{
    initWindow(argc, argv, 400, 400, "Test2");
    welcome();
    int op;
    scanf("%d", &op);
    if (op == 1)
        glutDisplayFunc(&graphy1); 
    else
    {
        printf("���������εĶ�������1<n<100��: ");
        while (~scanf("%d", &cnt))
        {
            if (cnt == 5)
                glutDisplayFunc(&graphy2);
            else if (cnt > 1 && cnt < 100)
                glutDisplayFunc(&graphy3);
            else
            {
                printf("���������������������룺");
                continue;
            }
            break;
        }
    }
    glutMainLoop();
    return 0;
}
