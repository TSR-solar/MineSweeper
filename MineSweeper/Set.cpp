#include "minesweeper.h"

// 绘制设置界面以及跳转
int Set()
{
	cleardevice();	// 清屏

	// 重新绘制标题和作者
	putimage(650, 100, 250, 200, &img1, title.x, title.y);
	putimage(1100, 250, 200, 200, &img1, author.x, author.y);

	// 绘制难度、统计、返回按钮
	diff.print();
	stats.print();
	back.print();

	// 循环等待跳转操作
	while (1)
	{
		m = getmessage(EX_MOUSE);

		// 若点击难度，则进入难度界面
		if (diff.check() == 1)
		{
			while (1)
			{
				if (Diff() == -1)
				{
					break;
				}
			}
			break;
		}

		// 若点击统计，则进入统计界面
		else if (stats.check() == 1)
		{
			while (1)
			{
				if (Stats() == -1)
				{
					break;
				}
			}
			break;
		}

		// 若点击返回，则返回初始界面
		else if (back.check() == 1)
		{
			return -1;
		}
	}

	// 其它情况不动
	return 0;
}