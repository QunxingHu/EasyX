#include <iostream>
#include <time.h>
#include <graphics.h>
#include <conio.h>

// demo1: 字符矩阵
void CharacterShow(void)
{
	//初始化时间种子
	srand((unsigned)time(NULL));

	initgraph(640, 480);

	int x, y;
	char c;

	//设置字体
	settextstyle(16, 8, _T("Courier"));

	//设置颜色
	settextcolor(GREEN);
	setlinecolor(BLACK);

	for (int i = 0; i <= 479; i++) {
		//随机位置显示三个随机字母
		for (int j = 0; j < 3; j++) {
			x = (rand() % 80) * 8;
			y = (rand() % 20) * 24;
			c = (rand() % 26) + 65;
			outtextxy(x, y, c);
		}

		//划线擦掉一个像素行
		line(0, i, 639, i);

		Sleep(10);

		if (i >= 479)
			i = -1;

		//按任意键退出
		if (_kbhit())
			break;
	}
	closegraph();
}


//demo2: 星空
#define MAXSTAR 200		//星星数量
struct STAR
{
	double x;
	int	y;
	double step;
	COLORREF color;
};

STAR star[MAXSTAR];

// 初始化星星
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 480;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	//速度越快，颜色越亮
	int color = (int)(star[i].step * 255 / 6.0 + 0.5); 
	star[i].color = RGB(color, color, color);
}

// 移动星星
void MoveStar(int i)
{
	//擦掉原来的星星
	putpixel((int)star[i].x, star[i].y, 0);

	//重新计算位置
	star[i].x += star[i].step;
	if (star[i].x > 640)
		InitStar(i);
	//画新星星
	putpixel((int)star[i].x, star[i].y, star[i].color);
}

void ShowStars()
{
	srand((unsigned)time(NULL));
	initgraph(640, 480);

	//初始化所有星星
	for (int i = 0; i < MAXSTAR; i++) {
		InitStar(i);
		star[i].x = rand() % 640;
	}

	//绘制星空
	while (!_kbhit())
	{
		for (int i = 0; i < MAXSTAR; i++)
			MoveStar(i);
		Sleep(20);
	}
	closegraph();
}

//demo3: 鼠标操作
void MouseOpt()
{
	//定义鼠标消息
	MOUSEMSG mouse;
	initgraph(640, 480);

	while (true)
	{
		//获取鼠标消息
		mouse = GetMouseMsg();
		switch (mouse.uMsg)
		{
			case WM_MOUSEMOVE:
				// 鼠标移动的时候画小红点
				putpixel(mouse.x, mouse.y, RED);
				break;

			case WM_LBUTTONDOWN:
				//鼠标左键点击 + ctrl
				if (mouse.mkCtrl)
					rectangle(mouse.x - 10, mouse.y - 10, mouse.x + 10, mouse.y + 10);
				else
					rectangle(mouse.x - 5, mouse.y - 5, mouse.x + 5, mouse.y + 5);
				break;
			case WM_RBUTTONUP:
				closegraph();
				return;
			default:
				break;
		}
	}
}

//demo4: 彩虹
void ShowRainbow()
{
	//渐变天空（亮度的逐渐增加）
	float H = 190;	//色相
	float S = 1;	//饱和度
	float L = 0.7f;	//亮度
	initgraph(640, 480);

	for (int y = 0; y < 480; y++) {
		L += 0.0005f;
		setlinecolor(HSLtoRGB(H, S, L));
		line(0, y, 639, y);
	}

	//画彩虹（通过色相逐渐增加）
	H = 0;
	S = 1;
	L = 0.5f;
	setlinestyle(PS_SOLID, 3); //线宽为2

	for (int r = 400; r > 344; r--) {
		H += 5;
		setlinecolor(HSLtoRGB(H, S, L));
		circle(500, 480, r);
	}
	getch();
	closegraph();
}