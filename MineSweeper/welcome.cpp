#include "minesweeper.h"

// ���Ƴ�ʼ�����Լ���ת
int welcome()
{
	// ���������ӻ��崰��ת��������
	SetWorkingImage(NULL);
	cleardevice();	// ����

	// ���Ʊ��������
	putimage(650, 100, 250, 200, &img1, title.x, title.y);
	putimage(1100, 250, 200, 200, &img1, author.x, author.y);

	// ��ӡ��ť
	start.print();
	set.print();
	help.print();
	quit.print();

	// ѭ���ȴ���ת����
	while (1)
	{
		m = getmessage(EX_MOUSE);

		// �������ʼ��������welcome()������
		if (start.check() == 1)
		{
			return 1;
		}

		// ��������ã���������ý���
		else if (set.check() == 1)
		{
			while (1)
			{
				if (Set() == -1)
				{
					break;
				}
			}
			break;
		}

		// �����������������������
		else if (help.check() == 1)
		{
			while (1)
			{
				if (Help() == -1)
				{
					break;
				}
			}
			break;
		}

		// ������˳������˳���Ϸ
		else if (quit.check() == 1)
		{
			if (Quit() == 1)
			{
				return -1;
			}
		}
	}
	// �����������
	return 0;
}

