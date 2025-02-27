#include "minesweeper.h"		// 总头文件
ExMessage m;					// 记录鼠标信息的结构体
int game;						// 检测游戏状态，0是正常，1是跳转，-1是退出
clock_t Tstart, Tnow, Tpass;	// 记录开始、当前时间，并以此计算经过时间
int main()
{
	initgraph(LENTH, WIDTH, EX_DBLCLKS);	// 创建窗口，同时支持鼠标双击事件
	setbkcolor(RGB(160, 160, 160));			// 调整背景颜色
	cleardevice();							// 清屏以生效
	initImage();							// 预绘制图片到缓冲窗口
	load();									// 读取文件信息

	srand((unsigned)time(0));				// 用时间设置随机数种子
	
	// 循环等待游戏关闭
	while (1)
	{
		// 循环等待初始界面跳转操作
		while (1)
		{
			// 绘制初始界面以及跳转，0为正常，1为开始游戏，-1为退出游戏
			game = welcome();
			if (game != 0)
			{
				break;
			}
		}
		
		// 如果为-1则退出
		if (game == -1)
		{
			break;
		}

		// 循环等待游戏跳转操作
		while (1)
		{
			initGame();		// 游戏初始化

			// 循环等待游戏重新开始或退出
			while (1)
			{
				// 游戏内操作以及跳转，0为正常，1为重新开始，-1为退出游戏
				game = inGame();
				if (game != 0)
				{
					EndGame();		// 游戏结束收尾操作
					break;
				}
			}

			// 如果为-1则退出
			if (game == -1)
			{
				break;
			}
		}
	}

	closegraph();		// 关闭窗口
	return 0;
}