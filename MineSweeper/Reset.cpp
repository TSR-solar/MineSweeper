#include "minesweeper.h"

// 询问是否重置统计数据
int Reset()
{
	HWND hwnd = GetHWnd();
	// 是返回1，否返回0
	return (MessageBox(hwnd, _T("你确定要重置统计数据吗？"), _T("重置统计数据"), MB_YESNO) == IDYES);
}