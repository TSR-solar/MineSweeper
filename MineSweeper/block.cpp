#include "minesweeper.h"

// ���õؿ��type
void block::typeset(int i, int j)
{
	// ����õؿ��ǵ��ף���ֱ����Ϊ'X'
	if (mine == 1)
	{
		type = 'X';
		return;
	}

	// �����������Χ�ĵ����������������ؿ�����
	else
	{
		int cnt = 0;
		if (i != 0)		// �����ǽ��ͳ��
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
	// �������ڵؿ����棬��������ִ�����²���
	if (m.x >= i*50+Ox && m.x <= (i+1)*50+Ox && m.y >= j*50+Oy && m.y <= (j+1)*50+Oy)
	{
		// ���û�б��ڣ����Ϊ׼������
		if (dig == 0)
		{
			dig = 3;
		}

		// �������������ִ�еؿ�����
		switch (m.message)
		{
			// ���������������׼�����ڣ����ڿ�
			case WM_LBUTTONDOWN:
			{
				if (dig == 3)
				{
					dig = 1;
				}
				break;
			}
			// �����������Ҽ���׼�����ڣ����ǣ�����Ѿ���ǣ���ȡ�����
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
			// ���˫���������ұ�����������֣���ֱ���ڿ�ʣ��δ��ǵؿ�
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

	// �����겻�ڵؿ����棬��ָ�׼������Ϊû����
	else if (dig == 3)
	{
		dig = 0;
	}
	return 0;
}

// �����ڿ��ؿ�
void block::chain(int i, int j)
{
	// ����Χ8���ؿ���û���ڵ�����Ϊ���ڣ����ڵĺͱ�ǵĲ���
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

// ���еؿ�
block** map = NULL;