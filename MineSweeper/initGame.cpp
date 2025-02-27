#include "minesweeper.h"

// ��Ϸ��ʼ��
void initGame()
{
	cleardevice();	// ����

	// ���ü�ʱ��
	Tstart = clock();

	// �Ե�ͼ���ж�̬�ڴ����
	map = new block * [mode.len];
	for (int i = 0; i < mode.len; i++)
	{
		map[i] = new block[mode.wid];
	}

	// �Եؿ���г�ʼ��
	for (int cnt = 0; cnt < mode.mine; )
	{
		// ������ɵ���
		int i = rand() % mode.len;
		int j = rand() % mode.wid;
		if (map[i][j].mine != 1)
		{
			cnt++;
			map[i][j].mine = 1;
		}
	}

	// ���õؿ��type
	for (int j = 0; j < mode.wid; j++)
	{
		for (int i = 0; i < mode.len; i++)
		{
			map[i][j].typeset(i, j);
		}
	}

	// ���ԣ����˻����ն�������еؿ��״̬���൱�ڴ�
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