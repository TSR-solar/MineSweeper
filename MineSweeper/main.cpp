#include "minesweeper.h"		// ��ͷ�ļ�
ExMessage m;					// ��¼�����Ϣ�Ľṹ��
int game;						// �����Ϸ״̬��0��������1����ת��-1���˳�
clock_t Tstart, Tnow, Tpass;	// ��¼��ʼ����ǰʱ�䣬���Դ˼��㾭��ʱ��
int main()
{
	initgraph(LENTH, WIDTH, EX_DBLCLKS);	// �������ڣ�ͬʱ֧�����˫���¼�
	setbkcolor(RGB(160, 160, 160));			// ����������ɫ
	cleardevice();							// ��������Ч
	initImage();							// Ԥ����ͼƬ�����崰��
	load();									// ��ȡ�ļ���Ϣ

	srand((unsigned)time(0));				// ��ʱ���������������
	
	// ѭ���ȴ���Ϸ�ر�
	while (1)
	{
		// ѭ���ȴ���ʼ������ת����
		while (1)
		{
			// ���Ƴ�ʼ�����Լ���ת��0Ϊ������1Ϊ��ʼ��Ϸ��-1Ϊ�˳���Ϸ
			game = welcome();
			if (game != 0)
			{
				break;
			}
		}
		
		// ���Ϊ-1���˳�
		if (game == -1)
		{
			break;
		}

		// ѭ���ȴ���Ϸ��ת����
		while (1)
		{
			initGame();		// ��Ϸ��ʼ��

			// ѭ���ȴ���Ϸ���¿�ʼ���˳�
			while (1)
			{
				// ��Ϸ�ڲ����Լ���ת��0Ϊ������1Ϊ���¿�ʼ��-1Ϊ�˳���Ϸ
				game = inGame();
				if (game != 0)
				{
					EndGame();		// ��Ϸ������β����
					break;
				}
			}

			// ���Ϊ-1���˳�
			if (game == -1)
			{
				break;
			}
		}
	}

	closegraph();		// �رմ���
	return 0;
}