#include "minesweeper.h"

// ѯ���Ƿ�����ͳ������
int Reset()
{
	HWND hwnd = GetHWnd();
	// �Ƿ���1���񷵻�0
	return (MessageBox(hwnd, _T("��ȷ��Ҫ����ͳ��������"), _T("����ͳ������"), MB_YESNO) == IDYES);
}