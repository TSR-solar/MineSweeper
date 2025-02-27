#include "minesweeper.h"
IMAGE img1(LENTH, WIDTH);		// 缓冲窗口

// 预绘制图片到缓冲窗口
void initImage()
{
	// 绘制到缓冲窗口，同时将绘图背景设为透明
	SetWorkingImage(&img1);
	setbkcolor(RGB(160, 160, 160));
	setbkmode(TRANSPARENT);

	cleardevice();	// 清屏

	// 打印游戏名称及作者
	settextstyle(114, 0, _T("黑体"));
	settextcolor(BLACK);
	outtextxy(title.x, title.y, _T("扫雷"));

	settextstyle(50, 0, _T("Consolas"));
	settextcolor(BLACK);
	outtextxy(author.x, author.y, _T("By solxr"));

	// 打印地块
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	setfillcolor(DARKGRAY);
	setfillstyle(BS_SOLID);
	fillrectangle(undig.x, undig.y, undig.x + 50, undig.y + 50);

	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	setfillcolor(LIGHTGRAY);
	setfillstyle(BS_SOLID);
	fillrectangle(ready.x, ready.y, ready.x + 50, ready.y + 50);

	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	setfillcolor(DARKGRAY);
	setfillstyle(BS_SOLID);
	settextstyle(50, 0, _T("黑体"));
	settextcolor(RED);
	fillrectangle(flag.x, flag.y, flag.x + 50, flag.y + 50);
	outtextxy(flag.x+2, flag.y-6, _T("🚩"));

	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	setfillcolor(LIGHTGRAY);
	setfillstyle(BS_SOLID);
	fillrectangle(dig0.x, dig0.y, dig0.x + 50, dig0.y + 50);

	settextstyle(50, 0, _T("Consolas"));
	settextcolor(LIGHTBLUE);
	fillrectangle(dig1.x, dig1.y, dig1.x + 50, dig1.y + 50);
	outtextxy(dig1.x + 12, dig1.y - 2, _T("1"));

	settextstyle(50, 0, _T("Consolas"));
	settextcolor(GREEN);
	fillrectangle(dig2.x, dig2.y, dig2.x + 50, dig2.y + 50);
	outtextxy(dig2.x + 12, dig2.y - 2, _T("2"));

	settextstyle(50, 0, _T("Consolas"));
	settextcolor(LIGHTRED);
	fillrectangle(dig3.x, dig3.y, dig3.x + 50, dig3.y + 50);
	outtextxy(dig3.x + 12, dig3.y - 2, _T("3"));

	settextcolor(BLUE);
	fillrectangle(dig4.x, dig4.y, dig4.x + 50, dig4.y + 50);
	outtextxy(dig4.x + 12, dig4.y - 2, _T("4"));

	settextcolor(RED);
	fillrectangle(dig5.x, dig5.y, dig5.x + 50, dig5.y + 50);
	outtextxy(dig5.x + 12, dig5.y - 2, _T("5"));

	settextcolor(CYAN);
	fillrectangle(dig6.x, dig6.y, dig6.x + 50, dig6.y + 50);
	outtextxy(dig6.x + 12, dig6.y - 2, _T("6"));

	settextcolor(BROWN);
	fillrectangle(dig7.x, dig7.y, dig7.x + 50, dig7.y + 50);
	outtextxy(dig7.x + 12, dig7.y - 2, _T("7"));

	settextcolor(DARKGRAY);
	fillrectangle(dig8.x, dig8.y, dig8.x + 50, dig8.y + 50);
	outtextxy(dig8.x + 12, dig8.y - 2, _T("8"));

	settextcolor(BLACK);
	fillrectangle(digX.x, digX.y, digX.x + 50, digX.y + 50);
	outtextxy(digX.x + 2, digX.y - 4, _T("💣"));
}