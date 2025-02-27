#include "minesweeper.h"
int Win()
{
	// 记录胜利局数和纪录
	FILE* fp1 = fopen("Tbest.txt", "w");
	FILE* fp2 = fopen("rate.txt", "w");

	// 将所有地雷标记并绘制
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
	
	// 增加胜利局数并判断是否打破纪录
	if (mode.len == 9 && mode.wid == 9 && mode.mine == 10)
	{
		win1++;
		if (Tpass < Tbest1)
		{
			_stprintf(s1, _T("用时：%d秒\n你创造了初级的最快纪录！\n是否要重新开始？"), Tpass);
			Tbest1 = Tpass;
		}
		else
		{
			_stprintf(s1, _T("用时：%d秒\n最快纪录：%d秒\n是否要重新开始？"), Tpass, Tbest1);
		}
	}
	else if (mode.len == 16 && mode.wid == 16 && mode.mine == 40)
	{
		win2++;
		if (Tpass < Tbest2)
		{
			_stprintf(s1, _T("用时：%d秒\n你创造了中级的最快纪录！\n是否要重新开始？"), Tpass);
			Tbest2 = Tpass;
		}
		else
		{
			_stprintf(s1, _T("用时：%d秒\n最快纪录：%d秒\n是否要重新开始？"), Tpass, Tbest2);
		}
	}
	else if (mode.len == 30 && mode.wid == 16 && mode.mine == 99)
	{
		win3++;
		if (Tpass < Tbest3)
		{
			_stprintf(s1, _T("用时：%d秒\n你创造了高级的最快纪录！\n是否要重新开始？"), Tpass);
			Tbest3 = Tpass;
		}
		else
		{
			_stprintf(s1, _T("用时：%d秒\n最快纪录：%d秒\n是否要重新开始？"), Tpass, Tbest3);
		}
	}
	else
	{
		_stprintf(s1, _T("用时：%d秒"), Tpass);
	}

	// 保存数据
	fprintf(fp1, "%d %d %d", Tbest1, Tbest2, Tbest3);
	fprintf(fp2, "%d %d %d %d %d %d", win1, lose1, win2, lose2, win3, lose3);
	
	HWND hwnd = GetHWnd();
	// 是返回1，否返回0
	return (MessageBox(hwnd, s1, _T("你胜利了！"), MB_YESNO) == IDYES);
}