#include "minesweeper.h"

// 询问是否退出游戏
int Quit()
{
	HWND h = GetHWnd();
	// 是返回1，否返回0
	return (MessageBox(h, _T("您确定要退出游戏吗？"), _T("ヽ（≧□≦）ノ"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK);
}