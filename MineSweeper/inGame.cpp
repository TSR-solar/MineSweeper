#include "minesweeper.h"
int safe;		// ��ȫ�ڿ��ؿ���
int danger;		// δ��ǵ�����

// ��Ϸ�ڲ����Լ���ת
int inGame()
{
	Tnow = clock();										// ��¼��ǰʱ��
	Tpass = (int)(Tnow - Tstart) / (CLOCKS_PER_SEC);	// ���㾭��ʱ��

	// ʵʱ���Ƶ�ǰ��Ϸ����
	paint();

	// ���¼��㰲ȫ�ڿ��ؿ�����δ��ǵ�����
	safe = 0;
	danger = mode.mine;

	m = getmessage(EX_MOUSE);

	// �����ؿ��Ը��µؿ�״̬�����㰲ȫ�ڿ��ؿ�����δ��ǵ��������Լ��ж��Ƿ�ʧ��
	for (int j = 0; j < mode.wid; j++)
	{
		for (int i = 0; i < mode.len; i++)
		{
			// ���µؿ�״̬
			map[i][j].check(i, j);

			// ���㰲ȫ�ڿ��ؿ���
			if (map[i][j].dig == 1 && map[i][j].mine == 0)
			{
				safe++;
			}

			// ����δ��ǵ�����
			if (map[i][j].dig == 2)
			{
				danger--;
			}

			// ����ڿ��ǿյؿ�������
			if (map[i][j].dig == 1 && map[i][j].type == '0')
			{
				map[i][j].chain(i, j);
			}

			// �ж��Ƿ�ʧ��
			if (map[i][j].dig == 1 && map[i][j].mine == 1)
			{
				// �����ʼ�µ���Ϸ�����¿�ʼ�����򷵻س�ʼ����
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

	// �ж��Ƿ�ʤ��
	if (safe == mode.len * mode.wid - mode.mine)
	{
		// �����ʼ�µ���Ϸ�����¿�ʼ�����򷵻س�ʼ����
		if (Win() == 1)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}

	// ��'R'���¿�ʼ
	if (GetAsyncKeyState('R') & 0x8000)
	{
		// �������¿�ʼ�����򲻶�
		if (Restart() == 1)
		{
			return 1;
		}
	}

	// ��'ESC'���س�ʼ����
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		// ���򷵻س�ʼ���棬���򲻶�
		if (End() == 1)
		{
			return -1;
		}
	}

	// ���������Ϸ��������
	return 0;
}