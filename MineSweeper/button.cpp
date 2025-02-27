#include "minesweeper.h"

// 构造函数
button::button(int x1, int y1, int x2, int y2, const TCHAR* s)
{
	left = x1;
	right = x2;
	top = y1;
	bottom = y2;
	_tcscpy(str, s);
}

// 检测按钮是否被按下
int button::check()
{
	// 确定按钮的位置
	RECT r = { left,top + 15,right,bottom };

	// 如果鼠标在按钮里面，则高亮显示按钮
	if (m.x >= left && m.x <= right && m.y >= top && m.y <= bottom)
	{
		setlinecolor(RGB(100,100,100));
		settextcolor(RGB(100,100,100));
		roundrect(left, top, right, bottom, ROUNDRATE, ROUNDRATE);
		drawtext(str, &r, DT_CENTER);

		// 如果按下左键，则执行按钮内容
		switch (m.message)
		{
			case WM_LBUTTONDOWN:
			{
				return 1;
			}
		}
	}

	// 如果鼠标不在按钮里面，则恢复原来的颜色
	else
	{
		setlinecolor(BLACK);
		settextcolor(BLACK);
		roundrect(left, top, right, bottom, ROUNDRATE, ROUNDRATE);
		drawtext(str, &r, DT_CENTER);
	}
	return 0;
}

// 绘制按钮
void button::print()
{
	// 设置线条和字体属性
	setlinestyle(PS_SOLID, 5, 0, 0);
	setlinecolor(BLACK);
	settextstyle(40, 0, _T("黑体"));
	settextcolor(BLACK);

	// 绘制圆角矩形和文字
	roundrect(left, top, right, bottom, ROUNDRATE, ROUNDRATE);
	RECT r = { left,top + 15,right,bottom };
	drawtext(str, &r, DT_CENTER);
}

button start(420, 420, 680, 490, _T("开始游戏"));		// 开始按钮
button set(820, 420, 1080, 490, _T("游戏设置"));			// 设置按钮
button help(420, 550, 680, 620, _T("游戏说明"));			// 帮助按钮
button quit(820, 550, 1080, 620, _T("退出游戏"));		// 退出按钮
button back(640, 700, 900, 770, _T("返回"));				// 返回按钮
button diff(420, 500, 680, 570, _T("调整难度"));			// 难度按钮
button stats(820, 500, 1080, 570, _T("数据统计"));		// 统计按钮
button reset(640, 600, 900, 670, _T("重置"));			// 重置按钮
button easy(220, 550, 480, 620, _T("初级"));				// 初级按钮
button mid(500, 550, 760, 620, _T("中级"));				// 中级按钮
button hard(780, 550, 1040, 620, _T("高级"));			// 高级按钮
button custom(1060, 550, 1320, 620, _T("自定义"));		// 自定义按钮