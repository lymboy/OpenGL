/////////////////////////////////////////////////////////////
// 程序名称：用绘图语句画安卓(android)机器人（初学 C 语言的同学必看）
// 编译环境：Visual C++ 6.0 / 2013，EasyX 20140321(beta)
// 作　　者：yangw80 <yw80@qq.com>
// 最后修改：2014-10-9
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
	// 创建大小为 800 * 600 的绘图窗口
	initgraph(800, 600);

	// 设置原点 (0, 0) 为屏幕中央（Y轴默认向下为正）
	setorigin(400, 300);

	// 使用藏青色填充背景
	setbkcolor(WHITE);
	cleardevice();

	// 设置绘图样式
	setlinecolor(BLACK);							// 设置线条颜色
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 1);	// 设置线条样式为宽度 10 的实线，端点是平的
    
    // 画大正方形的四个顶点
    line(0, -200, 201, 1);
    line(201, -1, 0, 200);
    line(0, 200, -200, 0);
    line(-200, 0, 0, -200);

    // 画三角形的底边
    line(-100, -100, 100, -100);
    line(100, -100, 100, 100);
    line(100, 100, -100, 100);
    line(-100, 100, -100, -100);
    
    // 画小正方形的四个顶点
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

	// 按任意键退出
	getchar();
	closegraph();

    return 0;
}