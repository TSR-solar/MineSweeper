#include "minesweeper.h"
// 游戏失败时操作
int Fail()
{
	// 记录失败局数
	FILE* fp2 = fopen("rate.txt", "w");

	// 翻开所有地雷并绘制
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

	// 增加失败局数
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

	// 保存数据
	fprintf(fp2, "%d %d %d %d %d %d", win1, lose1, win2, lose2, win3, lose3);

	// 询问是否开始新的游戏，是返回1，否返回0
	HWND hwnd = GetHWnd();
	return (MessageBox(hwnd, _T("是否要重新开始？"), _T("你失败了！"), MB_YESNO) == IDYES);
}