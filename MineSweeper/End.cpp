#include "minesweeper.h"
// ѯ���Ƿ������Ϸ�����س�ʼ����
int End()
{
	// ��ȡ���ھ��
	HWND hwnd = GetHWnd();

	// �Ƿ���1���񷵻�0
	return (MessageBox(hwnd, _T("��ȷ��Ҫ������Ϸ��������������"), _T("������Ϸ"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK);
}