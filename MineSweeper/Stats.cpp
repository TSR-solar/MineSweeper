#include "minesweeper.h"
clock_t Tbest1 = 9999, Tbest2 = 9999, Tbest3 = 9999;		// �������м����߼�����¼
int win1 = 0, win2 = 0, win3 = 0;				// �������м����߼�ʤ������
int lose1 = 0, lose2 = 0, lose3 = 0;			// �������м����߼�ʧ�ܾ���
int Stats()
{
	// ��¼ʤ�������ͼ�¼
	FILE* fp1 = fopen("Tbest.txt", "w");
	FILE* fp2 = fopen("rate.txt", "w");

	cleardevice();	// ����

	// ���»��Ʊ��������
	putimage(650, 100, 250, 200, &img1, title.x, title.y);
	putimage(1100, 250, 200, 200, &img1, author.x, author.y);

	// �������á����ذ�ť
	reset.print();
	back.print();

	// ���Ƶ�ǰͳ����Ϣ
	settextstyle(40, 0, _T("����"));
	settextcolor(BLACK);

	TCHAR s1[STRLEN] = { 0 }, s2[STRLEN] = { 0 }, s3[STRLEN] = { 0 };
	_stprintf(s1, _T("��������¼��%4d s  ʤ��%3d  ����%3d"), Tbest1, win1, lose1);
	_stprintf(s2, _T("�м�����¼��%4d s  ʤ��%3d  ����%3d"), Tbest2, win2, lose2);
	_stprintf(s3, _T("�߼�����¼��%4d s  ʤ��%3d  ����%3d"), Tbest3, win3, lose3);

	outtextxy(400, 400, s1);
	outtextxy(400, 450, s2);
	outtextxy(400, 500, s3);
	
	// ѭ���ȴ���ת����
	while (1)
	{
		m = getmessage(EX_MOUSE);

		// ��������ã�����������
		if (reset.check() == 1)
		{
			if (Reset() == 1)
			{
				Tbest1 = Tbest2 = Tbest3 = 9999;
				win1 = win2 = win3 = 0;
				lose1 = lose2 = lose3 = 0;
			}
			break;
		}
		// ��������أ��򷵻����ý���
		else if (back.check() == 1)
		{
			fprintf(fp1, "%d %d %d", Tbest1, Tbest2, Tbest3);
			fprintf(fp2, "%d %d %d %d %d %d", win1, lose1, win2, lose2, win3, lose3);
			_fcloseall();
			return -1;
		}
	}
	// �����������
	return 0;
}