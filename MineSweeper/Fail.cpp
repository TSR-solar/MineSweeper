#include "minesweeper.h"
// ��Ϸʧ��ʱ����
int Fail()
{
	// ��¼ʧ�ܾ���
	FILE* fp2 = fopen("rate.txt", "w");

	// �������е��ײ�����
	for (int j = 0; j < mode.wid; j++)
	{
		for (int i = 0; i < mode.len; i++)
		{
			if (map[i][j].mine == 1)
			{
				map[i][j].dig = 1;
			}
		}
	}
	paint();

	// ����ʧ�ܾ���
	if (mode.len == 9 && mode.wid == 9 && mode.mine == 10)
	{
		lose1++;
	}
	else if (mode.len == 16 && mode.wid == 16 && mode.mine == 40)
	{
		lose2++;
	}
	else if (mode.len == 30 && mode.wid == 16 && mode.mine == 99)
	{
		lose3++;
	}

	// ��������
	fprintf(fp2, "%d %d %d %d %d %d", win1, lose1, win2, lose2, win3, lose3);

	// ѯ���Ƿ�ʼ�µ���Ϸ���Ƿ���1���񷵻�0
	HWND hwnd = GetHWnd();
	return (MessageBox(hwnd, _T("�Ƿ�Ҫ���¿�ʼ��"), _T("��ʧ���ˣ�"), MB_YESNO) == IDYES);
}