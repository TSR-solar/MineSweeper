#include "minesweeper.h"

// 绘制初始界面以及跳转
int welcome()
{
	// 将工作区从缓冲窗口转到主窗口
	SetWorkingImage(NULL);
	cleardevice();	// 清屏

	// 绘制标题和作者
	putimage(650, 100, 250, 200, &img1, title.x, title.y);
	putimage(1100, 250, 200, 200, &img1, author.x, author.y);

	// 打印按钮
	start.print();
	set.print();
	help.print();
	quit.print();

	// 循环等待跳转操作
	while (1)
	{
		m = getmessage(EX_MOUSE);

		// 如果按开始，则跳出welcome()函数；
		if (start.check() == 1)
		{
			return 1;
		}

		// 如果按设置，则进入设置界面
		else if (set.check() == 1)
		{
			while (1)
			{
				if (Set() == -1)
				{
					break;
				}
			}
			break;
		}

		// 如果按帮助，则进入帮助界面
		else if (help.check() == 1)
		{
			while (1)
			{
				if (Help() == -1)
				{
					break;
				}
			}
			break;
		}

		// 如果按退出，则退出游戏
		else if (quit.check() == 1)
		{
			if (Quit() == 1)
			{
				return -1;
			}
		}
	}
	// 其余情况不动
	return 0;
}

