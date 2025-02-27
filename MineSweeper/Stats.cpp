#include "minesweeper.h"
clock_t Tbest1 = 9999, Tbest2 = 9999, Tbest3 = 9999;		// 初级、中级、高级最快纪录
int win1 = 0, win2 = 0, win3 = 0;				// 初级、中级、高级胜利局数
int lose1 = 0, lose2 = 0, lose3 = 0;			// 初级、中级、高级失败局数
int Stats()
{
	// 记录胜负局数和纪录
	FILE* fp1 = fopen("Tbest.txt", "w");
	FILE* fp2 = fopen("rate.txt", "w");

	cleardevice();	// 清屏

	// 重新绘制标题和作者
	putimage(650, 100, 250, 200, &img1, title.x, title.y);
	putimage(1100, 250, 200, 200, &img1, author.x, author.y);

	// 绘制重置、返回按钮
	reset.print();
	back.print();

	// 绘制当前统计信息
	settextstyle(40, 0, _T("黑体"));
	settextcolor(BLACK);

	TCHAR s1[STRLEN] = { 0 }, s2[STRLEN] = { 0 }, s3[STRLEN] = { 0 };
	_stprintf(s1, _T("初级最快纪录：%4d s  胜：%3d  负：%3d"), Tbest1, win1, lose1);
	_stprintf(s2, _T("中级最快纪录：%4d s  胜：%3d  负：%3d"), Tbest2, win2, lose2);
	_stprintf(s3, _T("高级最快纪录：%4d s  胜：%3d  负：%3d"), Tbest3, win3, lose3);

	outtextxy(400, 400, s1);
	outtextxy(400, 450, s2);
	outtextxy(400, 500, s3);
	
	// 循环等待跳转操作
	while (1)
	{
		m = getmessage(EX_MOUSE);

		// 如果按重置，则重置数据
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
		// 如果按返回，则返回设置界面
		else if (back.check() == 1)
		{
			fprintf(fp1, "%d %d %d", Tbest1, Tbest2, Tbest3);
			fprintf(fp2, "%d %d %d %d %d %d", win1, lose1, win2, lose2, win3, lose3);
			_fcloseall();
			return -1;
		}
	}
	// 其它情况不动
	return 0;
}