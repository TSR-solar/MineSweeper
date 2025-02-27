#include "minesweeper.h"

// 读取文件信息
void load()
{
	FILE* fp1, * fp2, * fp3;	// 文件指针
	int tmp;					// 纯凑数，为了让fscanf()有个返回值

	// 打开难度、纪录、胜负局数文本文件
	fp1 = fopen("diff.txt", "r");
	fp2 = fopen("Tbest.txt", "r");
	fp3 = fopen("rate.txt", "r");

	// 从文件中读取数据
	tmp = fscanf(fp1, "%d%d%d", &mode.len, &mode.wid, &mode.mine);
	tmp = fscanf(fp2, "%d%d%d", &Tbest1, &Tbest2, &Tbest3);
	tmp = fscanf(fp3, "%d%d%d%d%d%d", &win1, &lose1, &win2, &lose2, &win3, &lose3);

	// 关闭所有文件
	_fcloseall();
}