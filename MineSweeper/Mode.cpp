#include "minesweeper.h"

// �����Ѷ�
void Mode::set(int diff)
{
	// ���ݰ��µİ�ť�����Ѷȣ�1�ǳ�����2���м���3�Ǹ߼���4���Զ���
	switch (diff)
	{
		case 1:
		{
			// ����Ϊ9 * 9������10����
			len = 9; wid = 9; mine = 10;
			break;
		}
		case 2:
		{
			// �м�Ϊ16 * 16������40����
			len = 16; wid = 16; mine = 40;
			break;
		}
		case 3:
		{
			// �߼�Ϊ16 * 30������99����
			len = 30; wid = 16; mine = 99;
			break;
		}
		case 4:
		{
			// �Զ���
			TCHAR s[4] = { 0 };
			do
			{
				InputBox(s, 4, _T("���������ĳ���\n��Χ��9��30(Ĭ��Ϊ9)"), _T("����"), _T("9"));
				len = _ttoi(s);
			} while (len < 9 || len > 30);
			do
			{
				InputBox(s, 4, _T("���������Ŀ��\n��Χ��9��16(Ĭ��Ϊ9)"), _T("����"), _T("9"));
				wid = _ttoi(s);
			} while (wid < 9 || wid > 16);
			do
			{
				InputBox(s, 4, _T("��������׵�����\n��Χ�����Ϊ10�����Ϊ��������1/2��Ĭ��Ϊ10"), _T("����"), _T("10"));
				mine = _ttoi(s);
			} while (mine < 10 || mine > len*wid/2);
			break;
		}
		default:break;
	}
}

// ģʽ�������������ȡ���ȡ�������
Mode mode;