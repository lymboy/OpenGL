/////////////////////////////////////////////////////////////
// �������ƣ��û�ͼ��仭��׿(android)�����ˣ���ѧ C ���Ե�ͬѧ�ؿ���
// ���뻷����Visual C++ 6.0 / 2013��EasyX 20140321(beta)
// �������ߣ�yangw80 <yw80@qq.com>
// ����޸ģ�2014-10-9
//
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>

//#define PI 3.14159265

double PI = acos(-1);

int main()
{
	// ������СΪ 800 * 600 �Ļ�ͼ����
	initgraph(800, 600);

	// ����ԭ�� (0, 0) Ϊ��Ļ���루Y��Ĭ������Ϊ����
	setorigin(400, 300);

	// ʹ�ò���ɫ��䱳��
	setbkcolor(WHITE);
	cleardevice();

	// ���û�ͼ��ʽ
	setlinecolor(BLACK);							// ����������ɫ
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 1);	// ����������ʽΪ��� 10 ��ʵ�ߣ��˵���ƽ��
    
    // ���������ε��ĸ�����
    line(0, -200, 201, 1);
    line(201, -1, 0, 200);
    line(0, 200, -200, 0);
    line(-200, 0, 0, -200);

    // �������εĵױ�
    line(-100, -100, 100, -100);
    line(100, -100, 100, 100);
    line(100, 100, -100, 100);
    line(-100, 100, -100, -100);
    
    // ��С�����ε��ĸ�����
    line(-1, -101, 101, 1);
    line(101, -1, -1, 101);
    line(1, 101, -101, -1);
    line(-101, 1, 1, -101);
    setfillcolor(BROWN);
    floodfill(0, 0, BLACK);

    setfillcolor(MAGENTA);
    floodfill(0, -150, BLACK);

    setfillcolor(GREEN);
    floodfill(0, 150, BLACK);

    setfillcolor(CYAN);
    floodfill(150, 0, BLACK);

    setfillcolor(LIGHTMAGENTA);
    floodfill(-150, 0, BLACK);

	// ��������˳�
	getchar();
	closegraph();

    return 0;
}