#include "minesweeper.h"

// �����ѶȽ����Լ���ת
int Diff()
{
	
	FILE* fp1 = fopen("diff.txt", "w");		// ���ļ��Ա�������
	cleardevice();							// ����

	// ���»��Ʊ��⡢����
	putimage(650, 100, 250, 200, &img1, title.x, title.y);
	putimage(1100, 250, 200, 200, &img1, author.x, author.y);

	// ���Ʒ��ء��������м����߼���ť
	back.print();
	easy.print();
	mid.print();
	hard.print();
	custom.print();

	// ѭ���ȴ���ת����
	while (1)
	{

		// ���Ƶ�ǰ�Ѷ�
		TCHAR s1[STRLEN] = { 0 }, s2[STRLEN] = { 0 }, s3[STRLEN] = { 0 };
		_stprintf(s1, _T("��ǰ���ȣ�%2d"), mode.len);
		_stprintf(s2, _T("��ǰ��ȣ�%2d"), mode.wid);
		_stprintf(s3, _T("��ǰ��������%2d"), mode.mine);

		outtextxy(300, 400, s1);
		outtextxy(600, 400, s2);
		outtextxy(900, 400, s3);

		// ��ȡ�����Ϣ
		m = getmessage(EX_MOUSE);

		// ��������أ��򱣴沢�������ý���
		if (back.check() == 1)
		{
			fprintf(fp1, "%d %d %d", mode.len, mode.wid, mode.mine);
			fclose(fp1);
			return -1;
		}
		// ������ѶȰ�ť����������Ӧ�Ѷ�
		else if (easy.check() == 1)
		{
			mode.set(1);
		}
		else if (mid.check() == 1)
		{
			mode.set(2);
		}
		else if (hard.check() == 1)
		{
			mode.set(3);
		}
		else if (custom.check() == 1)
		{
			mode.set(4);
		}
	}
}