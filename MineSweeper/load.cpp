#include "minesweeper.h"

// ��ȡ�ļ���Ϣ
void load()
{
	FILE* fp1, * fp2, * fp3;	// �ļ�ָ��
	int tmp;					// ��������Ϊ����fscanf()�и�����ֵ

	// ���Ѷȡ���¼��ʤ�������ı��ļ�
	fp1 = fopen("diff.txt", "r");
	fp2 = fopen("Tbest.txt", "r");
	fp3 = fopen("rate.txt", "r");

	// ���ļ��ж�ȡ����
	tmp = fscanf(fp1, "%d%d%d", &mode.len, &mode.wid, &mode.mine);
	tmp = fscanf(fp2, "%d%d%d", &Tbest1, &Tbest2, &Tbest3);
	tmp = fscanf(fp3, "%d%d%d%d%d%d", &win1, &lose1, &win2, &lose2, &win3, &lose3);

	// �ر������ļ�
	_fcloseall();
}