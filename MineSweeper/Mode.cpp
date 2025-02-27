#include "minesweeper.h"

// 设置难度
void Mode::set(int diff)
{
	// 根据按下的按钮设置难度，1是初级，2是中级，3是高级，4是自定义
	switch (diff)
	{
		case 1:
		{
			// 初级为9 * 9个方块10个雷
			len = 9; wid = 9; mine = 10;
			break;
		}
		case 2:
		{
			// 中级为16 * 16个方块40个雷
			len = 16; wid = 16; mine = 40;
			break;
		}
		case 3:
		{
			// 高级为16 * 30个方块99个雷
			len = 30; wid = 16; mine = 99;
			break;
		}
		case 4:
		{
			// 自定义
			TCHAR s[4] = { 0 };
			do
			{
				InputBox(s, 4, _T("请输入矩阵的长度\n范围：9～30(默认为9)"), _T("输入"), _T("9"));
				len = _ttoi(s);
			} while (len < 9 || len > 30);
			do
			{
				InputBox(s, 4, _T("请输入矩阵的宽度\n范围：9～16(默认为9)"), _T("输入"), _T("9"));
				wid = _ttoi(s);
			} while (wid < 9 || wid > 16);
			do
			{
				InputBox(s, 4, _T("请输入地雷的数量\n范围：最低为10，最高为方格数的1/2，默认为10"), _T("输入"), _T("10"));
				mine = _ttoi(s);
			} while (mine < 10 || mine > len*wid/2);
			break;
		}
		default:break;
	}
}

// 模式参数，包括长度、宽度、地雷数
Mode mode;