#include "minesweeper.h"

// ѯ���Ƿ�ʼ�µ���Ϸ
int Restart()
{
	HWND hwnd = GetHWnd();
	// �Ƿ���1���񷵻�0
	return (MessageBox(hwnd, _T("��ȷ��Ҫ��ʼ�µ���Ϸ��"), _T("�µ���Ϸ"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK);
}