#include "minesweeper.h"

// 询问是否开始新的游戏
int Restart()
{
	HWND hwnd = GetHWnd();
	// 是返回1，否返回0
	return (MessageBox(hwnd, _T("您确定要开始新的游戏吗？"), _T("新的游戏"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK);
}