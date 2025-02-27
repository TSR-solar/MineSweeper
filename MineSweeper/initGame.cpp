#include "minesweeper.h"

// 游戏初始化
void initGame()
{
	cleardevice();	// 清屏

	// 重置计时器
	Tstart = clock();

	// 对地图进行动态内存分配
	map = new block * [mode.len];
	for (int i = 0; i < mode.len; i++)
	{
		map[i] = new block[mode.wid];
	}

	// 对地块进行初始化
	for (int cnt = 0; cnt < mode.mine; )
	{
		// 随机生成地雷
		int i = rand() % mode.len;
		int j = rand() % mode.wid;
		if (map[i][j].mine != 1)
		{
			cnt++;
			map[i][j].mine = 1;
		}
	}

	// 设置地块的type
	for (int j = 0; j < mode.wid; j++)
	{
		for (int i = 0; i < mode.len; i++)
		{
			map[i][j].typeset(i, j);
		}
	}

	// 调试，完了会在终端输出所有地块的状态，相当于答案
	/*for (int j = 0; j < mode.wid; j++)
	{
		for (int i = 0; i < mode.len; i++)
		{
			printf("%c ", map[i][j].type);
		}
		printf("\n");
	}
	printf("\n");*/

	return;
}