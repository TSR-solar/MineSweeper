#include "minesweeper.h"

// ���캯��
button::button(int x1, int y1, int x2, int y2, const TCHAR* s)
{
	left = x1;
	right = x2;
	top = y1;
	bottom = y2;
	_tcscpy(str, s);
}

// ��ⰴť�Ƿ񱻰���
int button::check()
{
	// ȷ����ť��λ��
	RECT r = { left,top + 15,right,bottom };

	// �������ڰ�ť���棬�������ʾ��ť
	if (m.x >= left && m.x <= right && m.y >= top && m.y <= bottom)
	{
		setlinecolor(RGB(100,100,100));
		settextcolor(RGB(100,100,100));
		roundrect(left, top, right, bottom, ROUNDRATE, ROUNDRATE);
		drawtext(str, &r, DT_CENTER);

		// ��������������ִ�а�ť����
		switch (m.message)
		{
			case WM_LBUTTONDOWN:
			{
				return 1;
			}
		}
	}

	// �����겻�ڰ�ť���棬��ָ�ԭ������ɫ
	else
	{
		setlinecolor(BLACK);
		settextcolor(BLACK);
		roundrect(left, top, right, bottom, ROUNDRATE, ROUNDRATE);
		drawtext(str, &r, DT_CENTER);
	}
	return 0;
}

// ���ư�ť
void button::print()
{
	// ������������������
	setlinestyle(PS_SOLID, 5, 0, 0);
	setlinecolor(BLACK);
	settextstyle(40, 0, _T("����"));
	settextcolor(BLACK);

	// ����Բ�Ǿ��κ�����
	roundrect(left, top, right, bottom, ROUNDRATE, ROUNDRATE);
	RECT r = { left,top + 15,right,bottom };
	drawtext(str, &r, DT_CENTER);
}

button start(420, 420, 680, 490, _T("��ʼ��Ϸ"));		// ��ʼ��ť
button set(820, 420, 1080, 490, _T("��Ϸ����"));			// ���ð�ť
button help(420, 550, 680, 620, _T("��Ϸ˵��"));			// ������ť
button quit(820, 550, 1080, 620, _T("�˳���Ϸ"));		// �˳���ť
button back(640, 700, 900, 770, _T("����"));				// ���ذ�ť
button diff(420, 500, 680, 570, _T("�����Ѷ�"));			// �ѶȰ�ť
button stats(820, 500, 1080, 570, _T("����ͳ��"));		// ͳ�ư�ť
button reset(640, 600, 900, 670, _T("����"));			// ���ð�ť
button easy(220, 550, 480, 620, _T("����"));				// ������ť
button mid(500, 550, 760, 620, _T("�м�"));				// �м���ť
button hard(780, 550, 1040, 620, _T("�߼�"));			// �߼���ť
button custom(1060, 550, 1320, 620, _T("�Զ���"));		// �Զ��尴ť