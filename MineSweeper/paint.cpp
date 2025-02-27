#include "minesweeper.h"
int Ox;		// �ؿ�����ԭ�������
int Oy;		// �ؿ�����ԭ��������

void paint()
{
	// �������ϽǷ��������
	Ox = MIDX - mode.len * 50 / 2;
	Oy = MIDY - mode.wid * 50 / 2;

	// ���Ƽ�ʱ����δ��ǵ�����
	settextstyle(50, 0, _T("����"));
	settextcolor(BLACK);
	TCHAR s1[STRLEN], s2[STRLEN];

	_stprintf(s1, _T("δ��ǵ�������%2d"), danger);
	_stprintf(s2, _T("��Ϸʱ�䣺%4ds"), Tpass);
	outtextxy(1100, 0, s1);
	outtextxy(0, 0, s2);

	// ���ݵؿ����ͻ��Ƶؿ飬ʹ��������ͼ��ʽ����������˸
	BeginBatchDraw();
	for (int j = 0; j < mode.wid; j++)
	{
		for (int i = 0; i < mode.len; i++)
		{

			if (map[i][j].dig == 0)
			{
				putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, undig.x, undig.y);
			}

			if (map[i][j].dig == 3)
			{
				putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, ready.x, ready.y);
			}

			if (map[i][j].dig == 2)
			{
				putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, flag.x, flag.y);
			}

			if (map[i][j].dig == 1)
			{
				switch (map[i][j].type)
				{
					case '0':
					{
						putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, dig0.x, dig0.y);
						break;
					}
					case '1':
					{
						putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, dig1.x, dig1.y);
						break;
					}
					case '2':
					{
						putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, dig2.x, dig2.y);
						break;
					}
					case '3':
					{
						putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, dig3.x, dig3.y);
						break;
					}
					case '4':
					{
						putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, dig4.x, dig4.y);
						break;
					}
					case '5':
					{
						putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, dig5.x, dig5.y);
						break;
					}
					case '6':
					{
						putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, dig6.x, dig6.y);
						break;
					}
					case '7':
					{
						putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, dig7.x, dig7.y);
						break;
					}
					case '8':
					{
						putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, dig8.x, dig8.y);
						break;
					}
					case 'X':
					{
						putimage(i * 50 + Ox, j * 50 + Oy, 53, 53, &img1, digX.x, digX.y);
						break;
					}
					default:break;
				}
			}
		}
	}

	FlushBatchDraw();
	EndBatchDraw();
}