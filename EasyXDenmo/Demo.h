#include <iostream>
#include <time.h>
#include <graphics.h>
#include <conio.h>

// demo1: �ַ�����
void CharacterShow(void)
{
	//��ʼ��ʱ������
	srand((unsigned)time(NULL));

	initgraph(640, 480);

	int x, y;
	char c;

	//��������
	settextstyle(16, 8, _T("Courier"));

	//������ɫ
	settextcolor(GREEN);
	setlinecolor(BLACK);

	for (int i = 0; i <= 479; i++) {
		//���λ����ʾ���������ĸ
		for (int j = 0; j < 3; j++) {
			x = (rand() % 80) * 8;
			y = (rand() % 20) * 24;
			c = (rand() % 26) + 65;
			outtextxy(x, y, c);
		}

		//���߲���һ��������
		line(0, i, 639, i);

		Sleep(10);

		if (i >= 479)
			i = -1;

		//��������˳�
		if (_kbhit())
			break;
	}
	closegraph();
}


//demo2: �ǿ�
#define MAXSTAR 200		//��������
struct STAR
{
	double x;
	int	y;
	double step;
	COLORREF color;
};

STAR star[MAXSTAR];

// ��ʼ������
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 480;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	//�ٶ�Խ�죬��ɫԽ��
	int color = (int)(star[i].step * 255 / 6.0 + 0.5); 
	star[i].color = RGB(color, color, color);
}

// �ƶ�����
void MoveStar(int i)
{
	//����ԭ��������
	putpixel((int)star[i].x, star[i].y, 0);

	//���¼���λ��
	star[i].x += star[i].step;
	if (star[i].x > 640)
		InitStar(i);
	//��������
	putpixel((int)star[i].x, star[i].y, star[i].color);
}

void ShowStars()
{
	srand((unsigned)time(NULL));
	initgraph(640, 480);

	//��ʼ����������
	for (int i = 0; i < MAXSTAR; i++) {
		InitStar(i);
		star[i].x = rand() % 640;
	}

	//�����ǿ�
	while (!_kbhit())
	{
		for (int i = 0; i < MAXSTAR; i++)
			MoveStar(i);
		Sleep(20);
	}
	closegraph();
}

//demo3: ������
void MouseOpt()
{
	//���������Ϣ
	MOUSEMSG mouse;
	initgraph(640, 480);

	while (true)
	{
		//��ȡ�����Ϣ
		mouse = GetMouseMsg();
		switch (mouse.uMsg)
		{
			case WM_MOUSEMOVE:
				// ����ƶ���ʱ��С���
				putpixel(mouse.x, mouse.y, RED);
				break;

			case WM_LBUTTONDOWN:
				//��������� + ctrl
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

//demo4: �ʺ�
void ShowRainbow()
{
	//������գ����ȵ������ӣ�
	float H = 190;	//ɫ��
	float S = 1;	//���Ͷ�
	float L = 0.7f;	//����
	initgraph(640, 480);

	for (int y = 0; y < 480; y++) {
		L += 0.0005f;
		setlinecolor(HSLtoRGB(H, S, L));
		line(0, y, 639, y);
	}

	//���ʺ磨ͨ��ɫ�������ӣ�
	H = 0;
	S = 1;
	L = 0.5f;
	setlinestyle(PS_SOLID, 3); //�߿�Ϊ2

	for (int r = 400; r > 344; r--) {
		H += 5;
		setlinecolor(HSLtoRGB(H, S, L));
		circle(500, 480, r);
	}
	getch();
	closegraph();
}