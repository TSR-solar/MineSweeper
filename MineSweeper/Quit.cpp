#include "minesweeper.h"

// ѯ���Ƿ��˳���Ϸ
int Quit()
{
	HWND h = GetHWnd();
	// �Ƿ���1���񷵻�0
	return (MessageBox(h, _T("��ȷ��Ҫ�˳���Ϸ��"), _T("�c���R���Q����"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK);
}