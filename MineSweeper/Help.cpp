#include "minesweeper.h"

// 绘制帮助界面以及跳转
int Help()
{
	cleardevice();	// 清屏

	// 重新绘制标题以及作者
	putimage(650, 100, 250, 200, &img1, title.x, title.y);
	putimage(1100, 250, 200, 200, &img1, author.x, author.y);

	// 打印说明
	settextstyle(40, 0, _T("黑体"));
	settextcolor(BLACK);
	RECT r0 = { 0, 350, 1600, 700 };
	drawtext(_T("扫雷的目标是识别出所有非雷区的格子，同时避免触碰到地雷。\n游戏区域由多个隐藏格子组成，每个格子可能隐藏着地雷或数字。\n数字表示周围八个格子中地雷的数量，而空格子会自动开启周围的8个格子。\n当你打开所有非雷区的格子时，你就赢了；\n但是当你触碰到地雷时，你就输了！\n游戏中，当你认为某个方格隐藏的是地雷时，可以用右键点击方格标记。\n当数字周围有足够多的标记时，可以双击数字开启周围剩余的地块。\n按ESC可以返回主界面，按R可以开始新的游戏。"), &r0, DT_CENTER);

	// 绘制返回按钮
	back.print();

	// 循环等待跳转操作
	while (1)
	{
		m = getmessage(EX_MOUSE);

		// 若点击返回，则返回初始界面
		if (back.check() == 1)
		{
			return -1;
		}
	}
}