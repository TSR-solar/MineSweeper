#include "minesweeper.h"

// ��Ϸ������β����
void EndGame()
{
	// �ͷ��ڴ�
	if (map != NULL)
	{
		for (int i = 0; i < mode.len; i++)
			delete[] map[i];
		delete[] map;
	}
}