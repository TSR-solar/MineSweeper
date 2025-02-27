#include "minesweeper.h"

// 设置地块的type
void block::typeset(int i, int j)
{
	// 如果该地块是地雷，则直接设为'X'
	if (mine == 1)
	{
		type = 'X';
		return;
	}

	// 否则计算其周围的地雷数量，来决定地块数字
	else
	{
		int cnt = 0;
		if (i != 0)		// 如果是墙则不统计
		{
			if (map[i - 1][j].mine == 1)
			{
				cnt++;
			}
		}

		if(i != mode.len - 1)
		{
			if (map[i + 1][j].mine == 1)
			{
				cnt++;
			}
		}

		if(j != 0)
		{
			if (map[i][j - 1].mine == 1)
			{
				cnt++;
			}
		}

		if(j != mode.wid - 1)
		{
			if (map[i][j + 1].mine == 1)
			{
				cnt++;
			}
		}

		if(i != 0 && j != 0)
		{
			if (map[i - 1][j - 1].mine == 1)
			{
				cnt++;
			}
		}

		if(i != 0 && j != mode.wid - 1)
		{
			if (map[i - 1][j + 1].mine == 1)
			{
				cnt++;
			}
		}

		if(i != mode.len -1 && j != 0)
		{
			if (map[i + 1][j - 1].mine == 1)
			{
				cnt++;
			}
		}

		if(i != mode.len - 1 && j != mode.wid - 1)
		{
			if (map[i + 1][j + 1].mine == 1)
			{
				cnt++;
			}
		}

		type = '0'+cnt;
	}
	return;
}

int block::check(int i,int j)
{
	// 如果鼠标在地块里面，则根据情况执行以下操作
	if (m.x >= i*50+Ox && m.x <= (i+1)*50+Ox && m.y >= j*50+Oy && m.y <= (j+1)*50+Oy)
	{
		// 如果没有被挖，则变为准备被挖
		if (dig == 0)
		{
			dig = 3;
		}

		// 如果按鼠标键，则执行地块内容
		switch (m.message)
		{
			// 如果按下鼠标左键且准备被挖，则挖开
			case WM_LBUTTONDOWN:
			{
				if (dig == 3)
				{
					dig = 1;
				}
				break;
			}
			// 如果按下鼠标右键且准备被挖，则标记；如果已经标记，则取消标记
			case WM_RBUTTONDOWN:
			{
				if (dig == 3)
				{
					dig = 2;
				}
				else if (dig == 2)
				{
					dig = 0;
				}
				
				break;
			}
			// 如果双击鼠标左键且标记数等于数字，则直接挖开剩余未标记地块
			case WM_LBUTTONDBLCLK:
			{
				if (dig == 1)
				{
					int cnt = 0;
					if (i != 0 && map[i - 1][j].dig == 2)
					{
						cnt++;
					}

					if (i != mode.len - 1 && map[i + 1][j].dig == 2)
					{
						cnt++;
					}

					if (j != 0 && map[i][j - 1].dig == 2)
					{
						cnt++;
					}

					if (j != mode.wid - 1 && map[i][j + 1].dig == 2)
					{
						cnt++;
					}

					if (i != 0 && j != 0 && map[i - 1][j - 1].dig == 2)
					{
						cnt++;
					}

					if (i != 0 && j != mode.wid - 1 && map[i - 1][j + 1].dig == 2)
					{
						cnt++;
					}

					if (i != mode.len - 1 && j != 0 && map[i + 1][j - 1].dig == 2)
					{
						cnt++;
					}

					if (i != mode.len - 1 && j != mode.wid - 1 && map[i + 1][j + 1].dig == 2)
					{
						cnt++;
					}

					if (cnt + '0' == type)
					{
						chain(i, j);
					}
				}
				break;
			}
			default:break;
		}
	}

	// 如果鼠标不在地块里面，则恢复准备被挖为没被挖
	else if (dig == 3)
	{
		dig = 0;
	}
	return 0;
}

// 连锁挖开地块
void block::chain(int i, int j)
{
	// 将周围8个地块中没被挖的设置为被挖，被挖的和标记的不动
	if (i != 0 && map[i - 1][j].dig == 0)
	{
		map[i - 1][j].dig = 1;
	}

	if (i != mode.len - 1 && map[i + 1][j].dig == 0)
	{
		map[i + 1][j].dig = 1;
	}

	if (j != 0 && map[i][j - 1].dig == 0)
	{
		map[i][j - 1].dig = 1;
	}

	if (j != mode.wid - 1 && map[i][j + 1].dig == 0)
	{
		map[i][j + 1].dig = 1;
	}

	if (i != 0 && j != 0 && map[i - 1][j - 1].dig == 0)
	{
		map[i - 1][j - 1].dig = 1;
	}

	if (i != 0 && j != mode.wid - 1 && map[i - 1][j + 1].dig == 0)
	{
		map[i - 1][j + 1].dig = 1;
	}

	if (i != mode.len - 1 && j != 0 && map[i + 1][j - 1].dig == 0)
	{
		map[i + 1][j - 1].dig = 1;
	}

	if (i != mode.len - 1 && j != mode.wid - 1 && map[i + 1][j + 1].dig == 0)
	{
		map[i + 1][j + 1].dig = 1;
	}
}

// 所有地块
block** map = NULL;