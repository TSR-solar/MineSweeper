#include "minesweeper.h"

// �������ý����Լ���ת
int Set()
{
	cleardevice();	// ����

	// ���»��Ʊ��������
	putimage(650, 100, 250, 200, &img1, title.x, title.y);
	putimage(1100, 250, 200, 200, &img1, author.x, author.y);

	// �����Ѷȡ�ͳ�ơ����ذ�ť
	diff.print();
	stats.print();
	back.print();

	// ѭ���ȴ���ת����
	while (1)
	{
		m = getmessage(EX_MOUSE);

		// ������Ѷȣ�������ѶȽ���
		if (diff.check() == 1)
		{
			while (1)
			{
				if (Diff() == -1)
				{
					break;
				}
			}
			break;
		}

		// �����ͳ�ƣ������ͳ�ƽ���
		else if (stats.check() == 1)
		{
			while (1)
			{
				if (Stats() == -1)
				{
					break;
				}
			}
			break;
		}

		// ��������أ��򷵻س�ʼ����
		else if (back.check() == 1)
		{
			return -1;
		}
	}

	// �����������
	return 0;
}