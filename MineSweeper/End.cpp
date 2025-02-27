#include "minesweeper.h"
// 询问是否结束游戏并返回初始界面
int End()
{
	// 获取窗口句柄
	HWND hwnd = GetHWnd();

	// 是返回1，否返回0
	return (MessageBox(hwnd, _T("您确定要结束游戏并返回主界面吗？"), _T("结束游戏"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK);
}