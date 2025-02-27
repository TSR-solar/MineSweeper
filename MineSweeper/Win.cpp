#include "minesweeper.h"
int Win()
{
	// ��¼ʤ�������ͼ�¼
	FILE* fp1 = fopen("Tbest.txt", "w");
	FILE* fp2 = fopen("rate.txt", "w");

	// �����е��ױ�ǲ�����
	for (int j = 0; j < mode.wid; j++)
	{
		for (int i = 0; i < mode.len; i++)
		{
			if (map[i][j].mine == 1)
			{
				map[i][j].dig = 2;
			}
		}
	}
	paint();
	

	TCHAR s1[STRLEN] = { 0 };
	
	// ����ʤ���������ж��Ƿ���Ƽ�¼
	if (mode.len == 9 && mode.wid == 9 && mode.mine == 10)
	{
		win1++;
		if (Tpass < Tbest1)
		{
			_stprintf(s1, _T("��ʱ��%d��\n�㴴���˳���������¼��\n�Ƿ�Ҫ���¿�ʼ��"), Tpass);
			Tbest1 = Tpass;
		}
		else
		{
			_stprintf(s1, _T("��ʱ��%d��\n����¼��%d��\n�Ƿ�Ҫ���¿�ʼ��"), Tpass, Tbest1);
		}
	}
	else if (mode.len == 16 && mode.wid == 16 && mode.mine == 40)
	{
		win2++;
		if (Tpass < Tbest2)
		{
			_stprintf(s1, _T("��ʱ��%d��\n�㴴�����м�������¼��\n�Ƿ�Ҫ���¿�ʼ��"), Tpass);
			Tbest2 = Tpass;
		}
		else
		{
			_stprintf(s1, _T("��ʱ��%d��\n����¼��%d��\n�Ƿ�Ҫ���¿�ʼ��"), Tpass, Tbest2);
		}
	}
	else if (mode.len == 30 && mode.wid == 16 && mode.mine == 99)
	{
		win3++;
		if (Tpass < Tbest3)
		{
			_stprintf(s1, _T("��ʱ��%d��\n�㴴���˸߼�������¼��\n�Ƿ�Ҫ���¿�ʼ��"), Tpass);
			Tbest3 = Tpass;
		}
		else
		{
			_stprintf(s1, _T("��ʱ��%d��\n����¼��%d��\n�Ƿ�Ҫ���¿�ʼ��"), Tpass, Tbest3);
		}
	}
	else
	{
		_stprintf(s1, _T("��ʱ��%d��"), Tpass);
	}

	// ��������
	fprintf(fp1, "%d %d %d", Tbest1, Tbest2, Tbest3);
	fprintf(fp2, "%d %d %d %d %d %d", win1, lose1, win2, lose2, win3, lose3);
	
	HWND hwnd = GetHWnd();
	// �Ƿ���1���񷵻�0
	return (MessageBox(hwnd, s1, _T("��ʤ���ˣ�"), MB_YESNO) == IDYES);
}