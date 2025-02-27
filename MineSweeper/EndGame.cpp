#include "minesweeper.h"

// 游戏结束收尾操作
void EndGame()
{
	// 释放内存
	if (map != NULL)
	{
		for (int i = 0; i < mode.len; i++)
			delete[] map[i];
		delete[] map;
	}
}