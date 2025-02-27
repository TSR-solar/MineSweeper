#include "minesweeper.h"
int safe;		// 安全挖开地块数
int danger;		// 未标记地雷数

// 游戏内操作以及跳转
int inGame()
{
	Tnow = clock();										// 记录当前时间
	Tpass = (int)(Tnow - Tstart) / (CLOCKS_PER_SEC);	// 计算经过时间

	// 实时绘制当前游戏画面
	paint();

	// 重新计算安全挖开地块数和未标记地雷数
	safe = 0;
	danger = mode.mine;

	m = getmessage(EX_MOUSE);

	// 遍历地块以更新地块状态，计算安全挖开地块数和未标记地雷数，以及判定是否失败
	for (int j = 0; j < mode.wid; j++)
	{
		for (int i = 0; i < mode.len; i++)
		{
			// 更新地块状态
			map[i][j].check(i, j);

			// 计算安全挖开地块数
			if (map[i][j].dig == 1 && map[i][j].mine == 0)
			{
				safe++;
			}

			// 计算未标记地雷数
			if (map[i][j].dig == 2)
			{
				danger--;
			}

			// 如果挖开是空地块则连锁
			if (map[i][j].dig == 1 && map[i][j].type == '0')
			{
				map[i][j].chain(i, j);
			}

			// 判定是否失败
			if (map[i][j].dig == 1 && map[i][j].mine == 1)
			{
				// 如果开始新的游戏则重新开始，否则返回初始界面
				if (Fail() == 1)
				{
					return 1;
				}
				else
				{
					return -1;
				}
			}
		}
	}

	// 判定是否胜利
	if (safe == mode.len * mode.wid - mode.mine)
	{
		// 如果开始新的游戏则重新开始，否则返回初始界面
		if (Win() == 1)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}

	// 按'R'重新开始
	if (GetAsyncKeyState('R') & 0x8000)
	{
		// 是则重新开始，否则不动
		if (Restart() == 1)
		{
			return 1;
		}
	}

	// 按'ESC'返回初始界面
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		// 是则返回初始界面，否则不动
		if (End() == 1)
		{
			return -1;
		}
	}

	// 其余情况游戏继续进行
	return 0;
}